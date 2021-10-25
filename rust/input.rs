#![allow(dead_code)]
#![allow(unused_imports)]
#![allow(non_snake_case)]
#![allow(unused_must_use)]

use std::{
    *,
    collections::*
};

// Mix-match
//
// different ways to construct the scanner
// 1. VecDeque<String>
// 2. Vec<String> and position on the vector
// 3. String and start position on the string (chosen here)
// 4. byte array and start position on the array
// 5. SplitWhitespace iterator (scope/lifetime issues)
//
// with different ways to read input
// 1. line by line (LineScanner)
// 2. whatever is available at the moment / interactively (InteractiveScanner)
// 3. single read till each EOF (SingleReadScanner)

#[derive(Default)]
pub struct LineScanner {
    buffer: String,
    start: usize
}
impl LineScanner {
	pub fn next<T: str::FromStr>(&mut self) -> T where T::Err: fmt::Debug {
        let mut iter = self.buffer[self.start..].split_ascii_whitespace();
        if let Some(token) = iter.next() {
            self.start = token.as_ptr() as usize - self.buffer.as_ptr() as usize + token.len();
            return token.parse().unwrap();
        }
        
        self.buffer.clear();
        io::stdin().read_line(&mut self.buffer).unwrap();
        self.start = 0;
        self.next()
    }
}

#[derive(Default)]
pub struct InteractiveScanner {
    buffer: String,
    start: usize
}
impl InteractiveScanner {
    pub fn next<T: str::FromStr>(&mut self) -> T where T::Err: fmt::Debug {
        let mut iter = self.buffer[self.start..].split_ascii_whitespace();
        if let Some(token) = iter.next() {
            self.start = token.as_ptr() as usize - self.buffer.as_ptr() as usize + token.len();
            return token.parse().unwrap();
        }
        
        let stdin = io::stdin();
        let buf_vec = stdin.lock().fill_buf().unwrap().to_vec();
        stdin.lock().consume(buf_vec.len()); // the lock must be released to avoid deadlock
        self.buffer = unsafe { String::from_utf8_unchecked(buf_vec) }; // str, &[u8] <-> String, Vec<u8>
        self.start = 0;
        self.next()
    }
}

#[derive(Default)]
pub struct SingleReadScanner {
    buffer: String,
    start: usize
}
impl SingleReadScanner {
    pub fn next<T: str::FromStr>(&mut self) -> T where T::Err: fmt::Debug {
        let mut iter = self.buffer[self.start..].split_ascii_whitespace();
        if let Some(token) = iter.next() {
            self.start = token.as_ptr() as usize - self.buffer.as_ptr() as usize + token.len();
            return token.parse().unwrap();
        }
        
        // re-use the buffer without allocating again
        let mut buf_vec = mem::take(&mut self.buffer).into_bytes();
        buf_vec.clear();
        io::stdin().read_to_end(&mut buf_vec).unwrap(); // read_to_end() blocks until EOF (ctrl + d)
        self.buffer = unsafe { String::from_utf8_unchecked(buf_vec) }; // str, &[u8] <-> String, Vec<u8>
        self.start = 0;
        self.next()
    }
}
#![allow(dead_code)]
#![allow(unused_imports)]
#![allow(non_snake_case)]
#![allow(unused_must_use)]

use std::{
    *,
    collections::*
};

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

fn main() {
    let mut scanner = Scanner::default();
    let T: usize = scanner.next();
    for tc in 1..T+1 {
        // print!("Case #{}: ", tc);
        solve();
    }
}

fn solve() {
    // println!();
}
#pragma once
#include "root.cpp"

// no sieve
TT> vector<T> gen_primes1(T max) {
    vector<T> primes;

    for (auto i = 2; i <= max; i++) {        

        // i's primality is unknown at this point
        for (auto j : primes) {
            if (1ll * j * j > i) break; // must be prime
            if (i % j == 0) goto next; // must not be prime
        }
        primes.push_back(i);
        next:;
    }
    return primes;
}

// sieve of eratosthenes
TT> vector<T> gen_primes2(T max) {
    vector<T> primes;
    vector<T> composite(max + 1, 0);

    // 1. populate the container holding the primes
    // 2. sieve the grid using the accumulated primes
    for (auto i = 2; i <= max; i++)

        // we already know if i is prime or not at this point
        if (!composite[i]) { // i must be prime
            primes.push_back(i);
      
            // all multiples of i which aren't guaranteed to have been visited yet by some smaller prime
            for (auto j = i * i; j <= max; j += i)
                composite[j] = 1;
        }

    return primes;
}

// sieve of eratosthenes (the grid stores the smallest prime factor instead of simply primality)
TT> vector<T> gen_primes3(T max) {
    vector<T> primes;
    vector<T> lpf(max + 1, 0); // least prime factor

    for (auto i = 2; i <= max; i++) {
        if (!lpf[i]) { // i must be prime
            lpf[i] = i;
            primes.push_back(i);            
        }
        
        // all multiples of i which haven't yet been visited by some smaller prime (i doesn't have to be prime here)
        for (auto j : primes) {
            auto num = i * j;
            if (!(j <= lpf[i] && num <= max)) break;
            lpf[num] = j;
        }
    }
    return primes;
}

TT> auto &gen_primes = gen_primes3<T>;
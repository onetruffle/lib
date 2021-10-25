#pragma once
#include "root.cpp"

// modular inverse
// b must be coprime to n
// (1/b) mod m
TT> T inv(T b, T m) {
    T x, y;
    assert(gcd(b, m, x, y) == 1);
    x = (x % m + m) % m; // this makes sure x is positive
    return x;
}

// modular division
// (a/b) mod m
TT> T div(T a, T b, T m) {
    return (a * inv(b, m)) % m;
}

// modular inverses of every +ve integer < m
// m must be coprime to all +ve integers < m, which means m must be prime
TT> vector<T> inv(T m) {
    vector<T> v(m);
    v[1] = 1;
    for(auto i = 2; i < m; ++i)
        v[i] = m - (m/i) * v[m % i] % m;
    return v;
}
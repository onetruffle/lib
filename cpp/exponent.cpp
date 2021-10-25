#pragma once
#include "root.cpp"

// modular power, modular exponentiation
// pow(a,b) mod m
ll pow(ll a, ll b, ll m){
    a %= m;
    ll acc = 1; // accumulator
    for (; b; b >>= 1) { // divide by 2
        if (b & 1) acc = (acc * a) % m;
        a = (a * a) % m; // square
    }
    return acc;
}
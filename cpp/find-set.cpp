#pragma once
#include "root.cpp"

// find the positions of the set bits
// 1 = set
// 0 = unset
vector<int> find_set(int x) {
    vector<int> v;
    
    auto pos = -1;
    while (x) {
        auto p = __builtin_ffs(x);
        v.push_back(pos += p);
        x >>= p;
    }
    return v;
}
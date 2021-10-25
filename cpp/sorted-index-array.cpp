#pragma once
#include "root.cpp"

vector <int> sort_indices(const int arr[], size_t size) {
    vector<int> v(size);
    iota(v.begin(), v.end(), 0);
    sort(v.begin(), v.end(), [&](int i, int j) { return arr[i] < arr[j]; });
    return v;
}
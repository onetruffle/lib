#pragma once
#include "root.cpp"

// euler totient function
vector<int> phi_vec(int n) {
    vector<int> phi(n + 1);
    iota(ALL(phi), 0);

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}
#pragma once
#include "root.cpp"

// extended euclidean / diophantine
// ax + by = gcd

// recursive
namespace Recursive {
    int gcd(int a, int b, int &x, int &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        int g = gcd(b, a % b, x, y);
        tie(x, y) = make_tuple(y, x - y * a / b);
        return g;
    }
}

// iterative
namespace Iterative {
    int gcd(int a, int b, int &x, int &y) {
        x = 1; y = 0;
        int x_next = 0, y_next = 1;
        while (b) {
            int q = a / b;
            tie(a, b) = make_tuple(b, a - q * b);
            tie(x, x_next) = make_tuple(x_next, x - q * x_next);
            tie(y, y_next) = make_tuple(y_next, y - q * y_next);
        }
        return a;
    }
}
#pragma once
#include "root.cpp"

namespace Reference {
    // greatest dividing power and exponent
    pll gdpe(ll &n, ll base) {   
        vector<pll> saved; // powers
        // ll [p, p_next] = {1, base};
        // ll [e, e_next] = {0, 1};
        ll p = 1, p_next = base;
        ll e = 0, e_next = 1;
        while (n % p_next == 0) {
            tie(p, p_next) = make_pair(p_next, p_next*p_next);
            tie(e, e_next) = make_pair(e_next, e_next*2);

            saved.emplace_back(p,e);
        }

        int accp = 1, acce = 0; // accumulator
        for (auto it = saved.rbegin(); it != saved.rend(); it++)
            if (n % it->first == 0) {
                n /= it->first;

                accp *= it->first;
                acce += it->second;
            }
        return {accp, acce};
    }
}

namespace Value {
    pll gdpe(ll n, ll base) {
        return Value::gdpe(n, base);
    }
}

// prime powers and exponents
map<ll,pll> ppe(ll n) {
    map<ll,pll> m;

    vector<ll> primes = gen_primes<ll>(sqrt(n));
    for (auto prime : primes)
        m[prime] = Reference::gdpe(n, prime);    
    if (n > 1) m[n] = {n, 1};

    return m;
}
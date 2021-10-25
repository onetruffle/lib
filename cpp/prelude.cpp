// #include "template.cpp"
// #include "root.cpp"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define REPEAT(n) for (auto _id112 = 0; _id112 < n; _id112++)
#define LOOP(i, s, n, d) for (auto i = s; i < n; i += d)
#define LOOPI(i, s, n, d) for (auto i = s; i <= n; i += d) // inclusive
#define LOOPL(i, s, n, d) for (auto i = s; i < s + n; i += d) // length

#define CONTAINS(container, x) (container.find(x) != container.end())
#define ALL(container) container.begin(), container.end()
#define RALL(container) container.rbegin(), container.rend()

#define C_UNSYNC ios::sync_with_stdio(0)
#define IO_UNSYNC cin.tie(0), cout.tie(0)

#define TT template < typename T
#define fn auto // rust

#define mod %
const auto modint = ll(1e9+7);

const auto newl = '\n';
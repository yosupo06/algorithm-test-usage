#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

// cin.tie(0);
// ios::sync_with_stdio(false);
// cout << setprecision(20) << fixed;

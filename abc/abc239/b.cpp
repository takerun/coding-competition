// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int int64;
template <class T>
inline T floor_x_yth(T x, T y) {
    // x/y: x(divident), y(divisor)
    return x >= 0 ? (x / y) : -((-x + y - 1) / y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int64 N;
    cin >> N;

    // logic

    // output
    cout << floor_x_yth(N, 10LL) << endl;
    return 0;
}
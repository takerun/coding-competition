// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
typedef long long int int64;

int main() {
    fastIO();
    // input
    int64 N, a, b;
    cin >> N;

    // logic
    int64 su = 0, maxdiff = -1;
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        maxdiff = max(maxdiff, b - a);
        su += a;
    }

    // output
    cout << su + maxdiff;
    cout << endl;
    return 0;
}
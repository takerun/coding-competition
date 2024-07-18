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
    int N;
    cin >> N;
    int s = 0;
    for(int i = 0; i < N - 1; i++) {
        int a;
        cin >> a;
        s += a;
    }

    // logic
    cout << -s;

    // output
    cout << endl;
    return 0;
}
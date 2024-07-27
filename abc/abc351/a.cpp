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
    int Asum = 0, Bsum = 0;

    // logic
    for(int i = 0; i < 9; i++) {
        int a;
        cin >> a;
        Asum += a;
    }
    for(int i = 0; i < 8; i++) {
        int b;
        cin >> b;
        Bsum += b;
    }

    // output
    cout << Asum - Bsum + 1;
    cout << endl;
    return 0;
}
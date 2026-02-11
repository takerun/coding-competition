// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
void Yes(bool a) { cout << (a ? "Yes" : "No") << endl; }
typedef long long int int64;

int main() {
    fastIO();
    // input
    int64 Sx, Sy, Tx, Ty;
    cin >> Sx >> Sy >> Tx >> Ty;

    // logic
    int64 dx = 0LL, dy = abs(Sy - Ty);
    if(Sx > Tx) {
        if(Sx % 2 == 1 and Sy % 2 == 0) Sx--;
        if(Sx % 2 == 0 and Sy % 2 == 1) Sx--;
        dx = Sx - Tx;
    } else if(Sx < Tx) {
        if(Sx % 2 == 0 and Sy % 2 == 0) Sx++;
        if(Sx % 2 == 1 and Sy % 2 == 1) Sx++;
        dx = Tx - Sx;
    } else {
        dx = 0LL;
    }
    int64 ans = 0LL;
    if(dx <= dy) {
        cout << dy << endl;
    } else {
        cout << (dx - dy - 1) / 2 + 1 + dy << endl;
    }

    // output
    return 0;
}
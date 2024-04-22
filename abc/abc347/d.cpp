// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
typedef unsigned long long int64;

int main() {
    fastIO();
    // input
    int64 a, b, C;
    cin >> a >> b >> C;

    // logic
    int64 c = 0;  // C's popcount
    int64 N = 63;
    for(int i = 0; i < N; i++) {
        if(C & (1LL << i)) {
            c++;
        }
    }

    int64 diff_ab = 0;
    if(a > b) {
        diff_ab = a - b;
    } else {
        diff_ab = b - a;
    }

    if((a + b + c) % 2 != 0 || a + b + c > 120 || a > b + c || b > c + a ||
       c > a + b) {
        cout << "-1" << endl;
        return 0;
    }

    int64 c_AB = min(a, b), c_A = 0, c_B = 0;
    if(a > b) {
        c_A = diff_ab;
    } else {
        c_B = diff_ab;
    }

    int64 buf = (c - max(c_A, c_B)) / 2;
    c_B += buf;
    c_A += buf;
    c_AB -= buf;

    int64 ansA = 0, ansB = 0, iA = 0, iB = 0, iAB = 0;
    for(int i = 0; i < N; i++) {
        if(C & (1LL << i)) {
            // this bit is 1
            if(iB < c_B) {
                ansB |= (1LL << i);
                iB++;
                continue;
            }
            if(iA < c_A) {
                ansA |= (1LL << i);
                iA++;
                continue;
            }
        } else {
            if(iAB < c_AB) {
                ansA |= (1LL << i);
                ansB |= (1LL << i);
                iAB++;
            }
        }
    }
    // output
    // cout << iA << " " << iB << " " << iAB << endl;
    cout << ansA << " " << ansB << endl;
    // cout << popcount(ansA) << " " << popcount(ansB) << endl;
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int A, B;
    cin >> A >> B;

    // logic
    int mod = B, x = A;
    int r = (x % mod + mod) % mod;
    int q = (x - r) / mod;
    if(r > (B / 2)) {
        cout << q + 1 << endl;
    } else {
        cout << q << endl;
    }

    // output

    return 0;
}
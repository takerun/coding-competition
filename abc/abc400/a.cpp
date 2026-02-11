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
    int A;
    cin >> A;

    // logic
    if(400 % A == 0) {
        cout << 400 / A << endl;
    } else {
        cout << -1 << endl;
    }

    // output

    return 0;
}
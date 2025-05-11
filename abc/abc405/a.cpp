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
    int R, X;
    cin >> R >> X;

    // logic
    if(X == 1) {
        if(R >= 1600 and R < 3000) {
            cout << "Yes" << endl;
            return 0;
        }
    } else {
        if(R >= 1200 and R < 2400) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    // output
    cout << "No" << endl;
    return 0;
}
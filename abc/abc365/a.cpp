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
    int Y;
    cin >> Y;

    // logic
    if(Y % 4 != 0) {
        cout << 365 << endl;
    } else if(Y % 100 != 0) {
        cout << 366 << endl;
    } else if(Y % 400 != 0) {
        cout << 365 << endl;
    } else {
        cout << 366 << endl;
    }

    // output

    return 0;
}
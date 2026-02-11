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
    int a, b;
    cin >> a >> b;

    // logic
    vector<int> A = {0, 1, 2};
    if(a == b) {
        cout << -1 << endl;
    } else {
        if(a * b == 2) {
            cout << 3 << endl;
        } else if(a * b == 3) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }
    }

    // output

    return 0;
}
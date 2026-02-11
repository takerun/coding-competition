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
    string ab, ac, bc;
    cin >> ab >> ac >> bc;

    // logic
    if(ab == bc) {
        cout << "B" << endl;
    }
    if(ab != ac) {
        cout << "A" << endl;
    }
    if(ac != bc) {
        cout << "C" << endl;
    }

    // output

    return 0;
}
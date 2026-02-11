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
    int64 H;
    cin >> H;

    // logic
    int i = 1;
    int64 h = 1;
    int64 hh = 1;
    while(hh <= H) {
        h *= 2;
        hh += h;
        i++;
    }

    // output
    cout << i << endl;
    return 0;
}
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
    int N, x, y, z, xx, yy;
    cin >> N >> x >> y >> z;

    // logic
    xx = min(x, y);
    yy = max(x, y);
    if(xx < z and z < yy) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    // output
    cout << endl;
    return 0;
}
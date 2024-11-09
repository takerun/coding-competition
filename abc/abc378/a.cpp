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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // logic
    map<int, int> s;
    s[a]++;
    s[b]++;
    s[c]++;
    s[d]++;

    // output
    int ans = 0;
    for(const auto &[key, val] : s) {
        if(val >= 2) ans++;
        if(val == 4) ans++;
    }
    cout << ans << endl;

    return 0;
}
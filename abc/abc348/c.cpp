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
    int N;
    cin >> N;
    map<int64, int64> mp;  // mpC] = A
    for(int i = 0; i < N; i++) {
        int64 a, c;
        cin >> a >> c;
        if(mp.count(c) == 0) mp[c] = a;
        mp[c] = min(mp[c], a);
    }

    // logic
    int64 mx = -1e18;
    for(const auto [key, val] : mp) {
        mx = max(mx, val);
    }

    // output
    cout << mx;
    cout << endl;
    return 0;
}
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
    int64 L, R;
    cin >> L >> R;

    // logic
    vector<int64> bi(62, 0);
    for(int i = 0; i < 62; i++) {
        bi[i] = (1LL << i);
    }

    vector<vector<int64>> ans;
    while(L < R) {
        int Li = -1;
        int64 j, r;
        do {
            Li++;
            j = L / bi[Li], r = bi[Li] * (j + 1);
        } while(L % bi[Li] == 0 and r <= R);
        Li--;
        j = L / bi[Li], r = bi[Li] * (j + 1);
        ans.push_back({L, r});
        L = r;
    }

    // output
    cout << ans.size() << endl;
    for(const auto &a : ans) cout << a[0] << " " << a[1] << endl;
    return 0;
}
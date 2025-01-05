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
    int64 mod = 1000000007LL;
    int N;
    cin >> N;
    vector<vector<int>> tree(N);
    vector<vector<int64>> weight(N);
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b, a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
        int64 w;
        cin >> w;
        weight[a].push_back(w);
        weight[b].push_back(w);
    }

    // logic
    vector<int64> dp(N, 0LL);
    int64 count0, count1;
    auto dfs_tree = [&](auto &&self, const int node, const int par,
                        const int64 w, const int64 digit) -> void {
        // shortcut

        // inflow logic
        if(par == -1) {
            dp[node] = 0LL;
        } else {
            dp[node] = dp[par] ^ (w & digit);
        }
        if(dp[node])
            count1++;
        else
            count0++;

        for(int i = 0; i < tree[node].size(); i++) {
            int chi = tree[node][i];
            if(chi == par) continue;
            self(self, chi, node, weight[node][i], digit);
        }
    };
    int64 ans = 0LL;
    for(int64 i = 0LL, num = 1LL << 60; num != 0LL; i++, num >>= 1LL) {
        int64 digit = 1LL << i;
        count0 = 0LL, count1 = 0LL;
        dfs_tree(dfs_tree, 0, -1, 0LL, digit);
        ans += digit % mod * count0 % mod * count1;
        ans %= mod;
    }

    // output
    cout << ans << endl;
    return 0;
}
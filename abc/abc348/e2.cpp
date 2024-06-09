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
    int N;
    cin >> N;
    vector<vector<int>> tree(N);
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int64> C(N);
    for(auto &c : C) cin >> c;

    // logic
    int root_ver = 0;
    // outer variable: vector<vector<int>> tree
    vector<int64> sumc_subtree(N, 0LL), d_subtree(N, 0LL);
    auto dfs_sumc = [&](auto &&self, const int ver, const int par) -> void {
        // parent side logic
        sumc_subtree[ver] += C[ver];
        d_subtree[ver] = 0LL;
        for(int i = 0; i < tree[ver].size(); i++) {
            int ver_sub = tree[ver][i];
            if(ver_sub == par) continue;
            // children side logic
            self(self, ver_sub, ver);
            sumc_subtree[ver] += sumc_subtree[ver_sub];
            d_subtree[ver] += d_subtree[ver_sub] + sumc_subtree[ver_sub];
        }
    };
    dfs_sumc(dfs_sumc, root_ver, -1);
    int64 sumc = sumc_subtree[root_ver];

    // https://ei1333.hateblo.jp/entry/2017/04/10/224413
    // outer variable: vector<vector<int>> tree
    vector<int64> score(N, 0LL);
    auto rerouting = [&](auto &&self, const int ver, const int par,
                         const int64 d_par) -> void {
        // solve ver's score
        score[ver] = d_subtree[ver] + d_par;
        for(int i = 0; i < tree[ver].size(); i++) {
            int ver_sub = tree[ver][i];
            if(ver_sub == par) continue;
            // prepare next parent side's score from children side
            int64 d_par_sub = score[ver] -
                              (d_subtree[ver_sub] + sumc_subtree[ver_sub]) +
                              (sumc - sumc_subtree[ver_sub]);
            self(self, ver_sub, ver, d_par_sub);
        }
    };
    rerouting(rerouting, root_ver, -1, 0);

    // output
    int64 mn = LLONG_MAX;
    for(int i = 0; i < N; i++) {
        mn = min(mn, score[i]);
    }
    cout << mn << endl;
    return 0;
}

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
    // outer variable: vector<vector<int>> tree, int64
    vector<int64> score_subtree(N, 0LL);
    auto dfs_tree = [&](auto &&self, const int ver, const int par) -> int64 {
        score_subtree[ver] += C[ver];
        for(int i = 0; i < tree[ver].size(); i++) {
            int ver_sub = tree[ver][i];
            if(ver_sub == par) continue;
            score_subtree[ver] += self(self, ver_sub, ver);
        }
        return score_subtree[ver];
    };
    dfs_tree(dfs_tree, 0, -1);

    int64 sumc = accumulate(begin(C), end(C), 0LL);
    auto dfs_tree_center = [&](auto &&self, const int ver,
                               const int par) -> int {
        bool flag = true;
        for(int i = 0; i < tree[ver].size(); i++) {
            int ver_sub = tree[ver][i];
            if(ver_sub == par) continue;
            // children side logic
            if(score_subtree[ver_sub] > sumc / 2) flag = false;

            int res = self(self, ver_sub, ver);
            if(res != -1) return res;
        }
        // parent side logic
        if((sumc - score_subtree[ver]) > sumc / 2) flag = false;
        return flag ? ver : -1;
    };
    const int center_id = dfs_tree_center(dfs_tree_center, 0, -1);

    vector<int64> score(N, 0LL);
    auto dfs_tree_calc = [&](auto &&self, const int ver, int par) -> int64 {
        score[ver] += C[ver];
        for(int i = 0; i < tree[ver].size(); i++) {
            int ver_sub = tree[ver][i];
            if(ver_sub == par) continue;
            // children side logic
            score[ver] += self(self, ver_sub, ver);
        }
        return score[ver];
    };
    dfs_tree_calc(dfs_tree_calc, center_id, -1);

    // output
    cout << accumulate(begin(score), end(score), 0LL) - score[center_id]
         << endl;
    return 0;
}
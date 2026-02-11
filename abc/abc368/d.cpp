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
    int N, K;
    cin >> N >> K;
    vector<vector<int>> tree(N);
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<bool> V(N, false);
    int v, root;
    cin >> v;
    v--;
    root = v;
    V[v] = true;
    for(int i = 1; i < K; i++) {
        cin >> v;
        v--;
        V[v] = true;
    }

    // logic
    // outer variable: vector<vector<int>> tree
    vector<int64> score_subtree(N, 0LL);
    auto dfs_tree = [&](auto &&self, const int ver, const int par) -> int64 {
        // ロジックは、葉-枝-根の順に確かめる
        // parent side logic
        // if(V[ver]) score_subtree[ver] += 1;
        for(int i = 0; i < tree[ver].size(); i++) {
            int ver_sub = tree[ver][i];
            if(ver_sub == par) continue;
            // shortcut
            // int res = self(self, ver_sub, ver);
            // if(res != -1) return res
            // children side logic
            score_subtree[ver] += self(self, ver_sub, ver);
        }
        // parent side logic
        if(score_subtree[ver] > 0 or V[ver]) score_subtree[ver] += 1;
        return score_subtree[ver];
    };

    cout << dfs_tree(dfs_tree, root, -1) << endl;

    // output

    return 0;
}
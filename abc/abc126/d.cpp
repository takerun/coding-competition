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
    vector<vector<int>> graph(N);
    map<vector<int>, int64> weight;
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        int64 w;
        cin >> w;
        weight[{u, v}] = w;
        weight[{v, u}] = w;
    }

    // logic
    // outer variable: vector<vector<int>> graph
    vector<int> color(N, -1);
    auto dfs_graph = [&](auto &&self, const int node, const int parent_clr,
                         const bool isEven) -> void {
        // shortcut

        // upside logic
        color[node] = isEven ? parent_clr : (1 - parent_clr);

        for(int i = 0; i < graph[node].size(); i++) {
            int chi = graph[node][i];
            if(color[chi] != -1) continue;
            self(self, chi, color[node], weight[{node, chi}] % 2 == 0);
        }
        // downside logic
        return;
    };
    dfs_graph(dfs_graph, 0, 0, true);

    // output
    for(const auto &a : color) cout << a << endl;
    return 0;
}
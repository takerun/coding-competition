// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
void Yes(bool a) { cout << (a ? "Yes" : "No") << endl; }
typedef long long int int64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
    }

    // logic
    // outer variable: vector<vector<int>> graph
    int found_node = -1;
    vector<bool> seen(N, false), finished(N, false);
    stack<int> history;
    auto dfs_graph = [&](auto &&self, const int node) -> void {
        // shortcut
        if(found_node != -1) return;
        // inflow logic
        if(seen[node] and !finished[node]) {
            found_node = node;
            return;
        }
        seen[node] = true;
        history.push(node);
        for(int i = 0; i < graph[node].size(); i++) {
            int chi = graph[node][i];
            if(finished[chi]) continue;
            self(self, chi);
        }
        // outflow logic
        if(found_node != -1) return;
        finished[node] = true;
        history.pop();
    };

    for(int i = 0; i < N; i++) {
        if(found_node != -1) break;
        if(finished[i]) continue;
        dfs_graph(dfs_graph, i);
    }
    vector<int> res;
    while(!history.empty()) {
        int v = history.top();
        history.pop();
        res.push_back(v);
        if(v == found_node) break;
    }
    reverse(begin(res), end(res));
    if(res.size() == 0) {
        cout << -1 << endl;
        return 0;
    }

    // remove bridge
    while(true) {
        vector<int> pos(N, -1);
        for(int i = 0; i < res.size(); i++) pos[res[i]] = i;
        int from = -1, to = -1;
        for(int i = 0; i < res.size(); i++) {
            int node = res[i], nnode = res[(i + 1) % res.size()];
            for(int j = 0; j < graph[node].size(); j++) {
                int next = graph[node][j];
                if(pos[next] != -1 and pos[next] != pos[nnode]) {
                    from = pos[node], to = pos[next];
                }
            }
        }
        // cout << from << " " << to << endl;
        if(from == -1) break;
        swap(from, to);
        vector<int> new_res;
        for(int i = from; i <= (from <= to ? to : to + res.size()); i++) {
            int ii = i % res.size();
            new_res.push_back(res[ii]);
        }
        res = new_res;
    }

    // output
    cout << res.size() << endl;
    for(const auto &a : res) cout << a + 1 << endl;
    return 0;
}
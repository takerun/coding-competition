#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;
constexpr int64 INF = (1LL << 60);
struct Edge {
    int to;
    int64 cost;
};
using Graph = vector<vector<Edge>>;
using Pair = pair<int64, int>;  // {distance, from}

// ダイクストラ法:
// 負の閉路がなければ実行可能
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
// Graph G(V);
//   G[from].emplace_back({to, cost});
// vector<int64> d(V, INF);
// Dijkstra(G, d, 0);
// cout << d[V - 1];
void Dijkstra(const Graph& graph, vector<int64>& distances, int startIndex) {
    // 「現時点での最短距離, 頂点」の順に取り出す priority_queue
    // デフォルトの priority_queue は降順に取り出すため greater を使う
    priority_queue<Pair, vector<Pair>, greater<Pair>> q;
    q.emplace((distances[startIndex] = 0), startIndex);

    while(!q.empty()) {
        const int64 distance = q.top().first;
        const int from = q.top().second;
        q.pop();

        // 最短距離でなければ処理しない
        if(distances[from] < distance) {
            continue;
        }

        // 現在の頂点からの各辺について
        for(const auto& edge : graph[from]) {
            // 連結がなければスキップする

            // to までの新しい距離
            const int64 d = (distances[from] + edge.cost);

            // d が現在の記録より小さければ更新
            if(d < distances[edge.to]) {
                q.emplace((distances[edge.to] = d), edge.to);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int64 N, M, X;
    cin >> N >> M >> X;

    Graph G(N * 2);
    vector<int64> d(N * 2, INF);
    for(int i = 0; i < M; i++) {
        int64 u, v;
        cin >> u >> v, u--, v--;

        G[u].emplace_back(v, 1LL);
        G[N + v].emplace_back(N + u, 1LL);
    }
    for(int i = 0; i < N; i++) {
        G[i].emplace_back(N + i, X);
        G[N + i].emplace_back(i, X);
    }

    // logic
    Dijkstra(G, d, 0);
    cout << min(d[N - 1], d[N * 2 - 1]);
    // output

    return 0;
}
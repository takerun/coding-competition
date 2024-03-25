#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
typedef long long int int64;

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
//   G[from].push_back({to, cost});
// vector<int64> d(V, INF);
// Dijkstra(G, d, 0);
// cout << d[V - 1];
void Dijkstra(const Graph& graph, vector<long long>& distances,
              int startIndex) {
    // 「現時点での最短距離, 頂点」の順に取り出す priority_queue
    // デフォルトの priority_queue は降順に取り出すため greater を使う
    priority_queue<Pair, vector<Pair>, greater<Pair>> q;
    q.emplace((distances[startIndex] = 0), startIndex);

    while(!q.empty()) {
        const long long distance = q.top().first;
        const int from = q.top().second;
        q.pop();

        // 最短距離でなければ処理しない
        if(distances[from] < distance) {
            continue;
        }

        // 現在の頂点からの各辺について
        for(const auto& edge : graph[from]) {
            // to までの新しい距離
            const long long d = (distances[from] + edge.cost);

            // d が現在の記録より小さければ更新
            if(d < distances[edge.to]) {
                q.emplace((distances[edge.to] = d), edge.to);
            }
        }
    }
}

int main() {
    fastIO();
    // input
    int V;
    cin >> V;
    Graph G(V);
    int a, b, x;
    for(int i = 0; i < V - 1; i++) {
        cin >> a >> b >> x;
        G[i].push_back({i + 1, a});
        G[i].push_back({x - 1, b});
    }

    // logic
    vector<int64> d(V, INF);
    Dijkstra(G, d, 0);

    // output
    cout << d[V - 1];
    cout << endl;
    return 0;
}
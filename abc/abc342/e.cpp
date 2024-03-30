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

constexpr int64 INF = (1LL << 60);
struct Edge {
    int64 l;
    int64 d;
    int64 k;
    int64 c;
    int to;
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
void Dijkstra(const Graph& graph, vector<int64>& distances, int startIndex) {
    // 「現時点での最遅時刻, 頂点」の順に取り出す priority_queue
    priority_queue<Pair, vector<Pair>> q;
    q.emplace((distances[startIndex] = INF), startIndex);

    while(!q.empty()) {
        const int64 distance = q.top().first;
        const int from = q.top().second;
        q.pop();

        // 最遅時刻でなければ処理しない
        if(distances[from] > distance) {
            continue;
        }

        // 現在の頂点からの各辺について
        for(const auto& edge : graph[from]) {
            // 連結がなければスキップ
            if(edge.l > distances[from] - edge.c) continue;

            // to までの新しい時刻
            int64 kk = (distances[from] - edge.c - edge.l) / edge.d;
            kk = (kk > edge.k - 1) ? edge.k - 1 : kk;
            const int64 d = edge.l + kk * edge.d;

            // d が現在の記録より遅ければ更新
            if(d > distances[edge.to]) {
                q.emplace((distances[edge.to] = d), edge.to);
            }
        }
    }
}

int main() {
    fastIO();
    // input
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for(int i = 0; i < M; i++) {
        int A, B;
        int64 l, d, k, c;
        cin >> l >> d >> k >> c >> A >> B;
        G[--B].emplace_back(Edge(l, d, k, c, --A));
    }

    // logic
    vector<int64> d(N, -INF);
    Dijkstra(G, d, N - 1);

    // output
    for(int i = 0; i < N - 1; i++) {
        if(d[i] == -INF) {
            cout << "Unreachable" << endl;
            continue;
        }

        cout << d[i] << endl;
    }
    cout << endl;
    return 0;
}
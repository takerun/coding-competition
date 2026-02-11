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
// https://atcoder.github.io/ac-library/production/document_en/dsu.html
#include <atcoder/dsu>
using dsu = atcoder::dsu;

int main() {
    fastIO();
    // input
    int N, M;
    cin >> N >> M;
    int64 minC = 1e10;
    dsu d(N);
    vector<int64> Num(N, 1e10);
    for(int i = 0; i < M; i++) {
        int64 K, C, a;
        cin >> K >> C;
        cin >> a;
        a--;
        Num[a] = min(Num[a], C);
        for(int j = 1; j < K; j++) {
            int64 aj;
            cin >> aj;
            aj--;
            Num[aj] = min(Num[aj], C);
            d.merge(a, aj);
        }
        minC = min(minC, C);
    }

    // logic
    if(d.groups().size() > 1) {
        cout << -1;
    } else {
        int64 sm = 0;
        for(int i = 0; i < N; i++) {
            sm += Num[i];
        }
        sm -= minC;
        cout << sm;
    }

    // output
    cout << endl;
    return 0;
}
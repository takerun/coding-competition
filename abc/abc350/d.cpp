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
    int64 N, M;
    cin >> N >> M;
    dsu d(N);
    for(int i = 0; i < M; i++) {
        int64 a, b;
        cin >> a >> b;
        d.merge(--a, --b);
    }

    // logic
    vector<int64> Gsize;
    size_t mx = 0;
    for(const auto &v : d.groups()) {
        Gsize.push_back(v.size());
        mx = max(mx, v.size());
    }

    // output
    vector<int64> cuml(mx + 1, 0);
    for(int i = 0; i < mx; i++) {
        cuml[i + 1] = cuml[i] + i + 1;
    }
    int64 full_connect = 0;
    for(int i = 0; i < Gsize.size(); i++) {
        full_connect += cuml[Gsize[i] - 1];
    }
    cout << full_connect - M;
    cout << endl;
    return 0;
}
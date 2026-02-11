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
template <class T>
inline bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    fastIO();
    // input
    int N;
    cin >> N;
    int MG;
    cin >> MG;
    vector<bool> G(100, false);
    for(int i = 0; i < MG; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u * 8 + v] = true;
    }
    int MH;
    cin >> MH;
    vector<bool> H(100, false);
    for(int i = 0; i < MH; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        H[a * 8 + b] = true;
    }
    vector<int> A(100, 0);
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            cin >> A[i * 8 + j];
        }
    }

    // logic
    int64 ans = LLONG_MAX;
    vector<int> P;
    for(int i = 0; i < N; i++) {
        P.emplace_back(i);
    }
    do {
        int64 buf = 0LL;
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                int hi = P[i], hj = P[j];
                if(hi > hj) swap(hi, hj);
                // cout << i << " " << j << " " << G[i * 8 + j] << " " << hi <<
                // " "
                //      << hj << " " << H[hi * 8 + hj] << endl;
                if(G[i * 8 + j] != H[hi * 8 + hj]) buf += A[hi * 8 + hj];
            }
        }
        chmin(ans, buf);
    } while(next_permutation(begin(P), end(P)));

    // output
    cout << ans << endl;
    return 0;
}
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
    int N, M;
    cin >> N >> M;
    vector<int64> X(M, 0);
    for(int64 &x : X) cin >> x;

    // logic
    // count
    vector<int64> imos(N + 1, 0);
    for(int i = 0; i < M - 1; i++) {
        int64 gr = X[i];
        int64 ls = X[i + 1];
        if(gr < ls) {
            gr = X[i + 1];
            ls = X[i];
        }
        int64 btw = gr - ls;
        imos[0] += btw;
        imos[ls - 1] += (N - btw) - btw;
        imos[gr - 1] += btw - (N - btw);
        imos[N] -= btw;
    }
    // simulate
    int64 mn = imos[0];
    int64 cuml = imos[0];
    for(int i = 1; i < N; i++) {
        cuml += imos[i];
        mn = min(mn, cuml);
    }

    // output
    cout << mn;
    cout << endl;
    return 0;
}
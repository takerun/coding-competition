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
template <class T>
inline bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

// 期待値DP、すごろく
int main() {
    fastIO();
    // input
    int N, M, K;
    cin >> N >> M >> K;
    vector<bool> A4find(N, false);
    for(int i = 0; i < K; i++) {
        int a;
        cin >> a;
        A4find[a] = true;
    }

    // logic
    // initialize dp
    vector<double> dp0(N + 1, 0), dp(N + 1, 0);

    // init sub score
    dp0[N] = 0;
    dp[N] = 0;

    double dp0buf = 0, dpbuf = 0;
    for(int i = N - 1; i >= 0; i--) {
        dp0buf += dp0[i + 1];
        dpbuf += dp[i + 1];
        if(i + M + 1 <= N) {
            dp0buf -= dp0[i + M + 1];
            dpbuf -= dp[i + M + 1];
        }
        // cout << dp0buf << " " << dpbuf << endl;

        if(A4find[i]) {
            dp0[i] = 1;
            dp[i] = 0;
        } else {
            dp0[i] = dp0buf / M;
            dp[i] = dpbuf / M;
            dp[i] += 1;
        }

        // 計算量の問題で以下の処理では不十分
        // if(A4find[i]) {
        //     dp0[i] = 1;
        //     dp[i] = 0;
        //     continue;
        // }
        // for(int j = 1; j <= M; j++) {
        //     if(i + j > N) continue;
        //     dp0[i] += dp0[i + j];
        //     dp[i] += dp[i + j];
        // }
        // dp0[i] /= M;
        // dp[i] /= M;
        // dp[i] += 1;
    }

    // output
    double EPS = 1e-9;
    if(abs(1.0 - dp0[0]) <= EPS) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(4);
        cout << (dp[0] / (1.0 - dp0[0])) << endl;
    }

    return 0;
}
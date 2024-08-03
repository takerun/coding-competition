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
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    // logic
    // N: 1-indexed, X: 1-indexed
    vector<vector<int>> dp(N + 1, vector<int>(X + 1, 1e5));
    dp[0] = vector<int>(X + 1, 0);
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = N; j >= 1; j--) {
            for(int k = X; k >= 1; k--) {
                if(k - A[i] < 0) continue;

                if(dp[j - 1][k - A[i]] + B[i] <= Y) {
                    ans = max(ans, j);
                    dp[j][k] = min(dp[j][k], dp[j - 1][k - A[i]] + B[i]);
                }
            }
        }
    }

    // output
    // for(int i = 0; i <= N; i++) {
    //     for(int j = 0; j <= X; j++) {
    //         cout << i << " " << j << " " << dp[i][j] << endl;
    //     }
    // }
    cout << min(ans + 1, N) << endl;
    return 0;
}
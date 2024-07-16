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
    string N;
    cin >> N;

    // logic
    int64 ans = 0LL;

    for(int s = 1; s < 9 * 14; s++) {
        int D = N.size(), I = s + 1, J = s, F = 2;
        vector dp(D + 1, vector(I, vector(J, vector(F, 0LL))));
        dp[0][0][0][0] = 1LL;
        for(int d = 0; d < D; d++) {
            int Nd = int(N[d] - '0');
            for(int i = 0; i < I; i++) {
                for(int j = 0; j < J; j++) {
                    // way to put the above together
                    for(int f = 0; f < F; f++) {
                        for(int t = 0; t < 10; t++) {
                            if(i + t >= I) continue;
                            if(!f and t > Nd) continue;
                            dp[d + 1][i + t][(j * 10 + t) % s][f || (t < Nd)] +=
                                dp[d][i][j][f];
                        }
                    }
                }
            }
        }
        ans += dp[D][s][0][1] + dp[D][s][0][0];
    }

    cout << ans;
    cout << endl;
    return 0;
}
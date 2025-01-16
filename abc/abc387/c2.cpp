#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int64 L, R;
    cin >> L >> R;

    // logic
    auto func = [&](int64 X) {
        string Ns = to_string(X);
        // digit * is_smaller(0-9 available) * get_out_of_leading_zero * hebi
        int D = Ns.size(), F = 2, Lz = 2, I = 10;
        vector dp(D + 1,
                  vector(F, vector(Lz, vector(I, 0LL))));  // value: count
        // seeds for hebi, not allowed to update dp[*][*][0][*]
        dp[0][0][0][0] = 1LL;
        for(int d = 1; d < D; d++)
            dp[d][1][0][0] = 1LL;  // for 0****, 00***, ...
        // digit dp
        for(int d = 0; d < D; d++) {
            int Nd = int(Ns[d] - '0');
            for(int f = 0; f < F; f++) {
                for(int lz = 0; lz < Lz; lz++) {
                    for(int i = 0; i < I; i++) {
                        for(int nx = 0; nx < 10; nx++) {
                            // smaller -> smaller, exact -> smaller, exact ->
                            // exact
                            if(not(f or (nx <= Nd))) continue;
                            int nf = f || (nx < Nd);
                            // get out of leading zero,
                            // not allowed to update dp[*][*][0][*]
                            int nlz = lz || nx > 0;
                            if(not nlz) continue;
                            // update dp
                            int ni = lz ? i : nx;
                            if(lz and nx >= i) continue;
                            dp[d + 1][nf][nlz][ni] += dp[d][f][lz][i];
                        }
                    }
                }
            }
        }
        int64 res = 0LL;
        for(int i = 0; i < I; i++) {
            res += dp[D][1][1][i] + dp[D][0][1][i];
        }
        return res;
    };

    // output
    cout << func(R) - func(L - 1) << endl;
    return 0;
}
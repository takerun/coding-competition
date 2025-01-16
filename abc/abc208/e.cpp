#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;
int64 pw(int64 a, int64 n) { return n == 0 ? 1LL : pw(a, n - 1) * a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    string Ns;
    int64 K;
    cin >> Ns >> K;

    // logic
    // digit * is_smaller(0-9 available) * get_out_of_leading_zero * prod_digit
    int D = Ns.size(), F = 2, Lz = 2;
    vector dp(D + 1, vector(F, vector<map<int64, int64>>(Lz)));  // value: count
    // seeds for prod, not allowed to update dp[*][*][0][*]
    dp[0][0][0][1] = 1LL;
    for(int d = 1; d < D; d++) dp[d][1][0][1] = 1LL;  // for 0****, 00***, ...
    // digit dp
    for(int d = 0; d < D; d++) {
        int Nd = int(Ns[d] - '0');
        for(int f = 0; f < F; f++) {
            for(int lz = 0; lz < Lz; lz++) {
                for(auto& [k, v] : dp[d][f][lz]) {
                    for(int nx = 0; nx < 10; nx++) {
                        // smaller -> smaller, exact -> smaller, exact -> exact
                        if(not(f or (nx <= Nd))) continue;
                        int nf = f || (nx < Nd);
                        // get out of leading zero,
                        // not allowed to update dp[*][*][0][*]
                        int nlz = lz || nx > 0;
                        if(not nlz) continue;
                        // update dp
                        int64 nk = k * nx;  // prod_digit
                        dp[d + 1][nf][nlz][nk] += dp[d][f][lz][k];
                    }
                }
            }
        }
    }

    // output
    int64 ans = 0LL;
    for(auto& [k, v] : dp[D][1][1])
        if(k <= K) ans += v;
    for(auto& [k, v] : dp[D][0][1])
        if(k <= K) ans += v;
    cout << ans << endl;
    return 0;
}
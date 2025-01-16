#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;
int64 mod = 1000000007LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    string Ns;
    cin >> Ns;
    int q;
    cin >> q;

    // logic
    // pattern of N = 063435:
    // 00000-59999, 60000-62999, 63000-63399, 63400-63429, 63430-63434, 63435
    // digit * is_smaller(0-9 available) * sum_digit
    int D = Ns.size(), F = 2, I = q;
    vector dp(D + 1, vector(F, vector(I, 0LL)));  // value: count
    dp[0][0][0] = 1LL;                            // seed for sum
    for(int d = 0; d < D; d++) {
        int Nd = int(Ns[d] - '0');
        for(int f = 0; f < F; f++) {
            for(int i = 0; i < I; i++) {
                // way to put the above together
                for(int nx = 0; nx < 10; nx++) {
                    if(not(f or (nx <= Nd))) continue;
                    int nf = f or (nx < Nd);
                    // update dp
                    int ni = (i + nx) % q;  // sum_digit
                    dp[d + 1][nf][ni] += dp[d][f][i] % mod;
                }
            }
        }
    }

    // output
    cout << (dp[D][1][0] + dp[D][0][0] - 1) % mod << endl;
    return 0;
}
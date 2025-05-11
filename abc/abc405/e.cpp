#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;
#include <atcoder/modint>
using mint = atcoder::modint998244353;
struct Binomial {
    // fac: n!, invfac: 1 / n!
    vector<mint> fac, invfac, inv;
    Binomial(int n) : fac(n + 1), invfac(n + 1), inv(n + 1) {
        fac[0] = invfac[0] = inv[0] = 1;
        for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
        invfac[n] = fac[n].inv();
        for(int i = n - 1; i >= 0; i--) {
            invfac[i] = invfac[i + 1] * (i + 1);
            inv[i + 1] = invfac[i + 1] * fac[i];
        }
    }
} Bi{3000001};
mint nCr(int n, int r) {
    if(n < r) return 0;
    if(n < 0 or r < 0) return 0;
    return Bi.fac[n] * Bi.invfac[r] * Bi.invfac[n - r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // input
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    // logic
    mint ans{0};
    for(int i = 0; i <= B; i++) {
        mint ai{nCr(A - 1 + i, i)};
        ai *= nCr(B - i + C + D, C);
        ans += ai;
    }

    // output
    cout << ans.val() << endl;
    return 0;
}
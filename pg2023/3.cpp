#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ft(i, f, t) for (int i = f; i < (int)(t); i++)
#define all(x) std::begin(x), std::end(x)
typedef long long int int64;

#include <atcoder/modint>
using mint = atcoder::modint998244353;
struct Binomial
{
    vector<mint> fac, invfac, inv;
    Binomial(int n) : fac(n + 1), invfac(n + 1), inv(n + 1)
    {
        fac[0] = invfac[0] = inv[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = fac[i - 1] * i;
        invfac[n] = fac[n].inv();
        for (int i = n - 1; i >= 0; i--)
        {
            invfac[i] = invfac[i + 1] * (i + 1);
            inv[i + 1] = invfac[i + 1] * fac[i];
        }
    }
} C{303030};

int main()
{
    fastIO();
    // input
    int N, K;
    cin >> N >> K;
    vector<int64> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    // logic
    mint ans = 1;
    for (int i = 0; i < K; i++)
    {
        map<int, int> mp;
        int all = 0;
        for (int j = i; j < N; j += K)
        {
            mp[A[j]]++, all++;
        }
        ans *= C.fac[all];
        for (auto &[_, val] : mp)
            ans *= C.invfac[val];
    }
    // output
    cout << ans.val();
    cout << endl;
    return 0;
}
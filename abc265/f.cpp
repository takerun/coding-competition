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

int main()
{
    fastIO();

    int MAX = 1001;
    int N, D;
    cin >> N >> D;
    vector<int> p(N), q(N);
    rep(i, N)
    {
        cin >> p[i];
    }
    rep(i, N)
    {
        cin >> q[i];
    }

    vector<vector<mint>> dp(MAX, vector<mint>(MAX)), ndp(MAX, vector<mint>(MAX));
    dp[0][0] = 1;
    rep(i, N)
    {
        rep(k, D + 1) rep(l, D + 1) ndp[k][l] = 0;
        int pi = p[i], qi = q[i];
        for (int mid = -2 * MAX; mid <= 2 * MAX; mid++)
        {
            int pd = abs(mid - pi);
            int qd = abs(mid - qi);
            if (max(pd, qd) > D)
                continue;
            for (int k = 0; k <= D - pd; k++)
            {
                for (int l = 0; l <= D - qd; l++)
                {
                    ndp[k + pd][l + qd] += dp[k][l];
                }
            }
        }

        cout << i << endl;
        rep(k, D + 2)
        {
            rep(l, D + 2)
            {
                cout << ndp[k][l].val() << " ";
            }
            cout << endl;
        }
        swap(dp, ndp);
    }

    mint ans = 0;
    rep(k, MAX) rep(l, MAX) ans += dp[k][l];
    cout << ans.val() << endl;
    return 0;
}
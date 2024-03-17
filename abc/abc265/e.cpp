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

    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> dxy;
    rep(i, 3)
    {
        int a, b;
        cin >> a >> b;
        dxy.push_back({a, b});
    }

    set<pair<int, int>> stop;
    rep(i, M)
    {
        int a, b;
        cin >> a >> b;
        stop.insert({a, b});
    }

    vector<vector<mint>> dp(1, vector<mint>(1));
    dp[0][0] = 1;
    rep(i, N)
    {
        vector<vector<mint>> next_dp(i + 2, vector<mint>(i + 2));
        rep(k, i + 1)
        {
            rep(l, i + 1)
            {
                int64 x = k * dxy[0].first + l * dxy[1].first + (i - k - l) * dxy[2].first;
                int64 y = k * dxy[0].second + l * dxy[1].second + (i - k - l) * dxy[2].second;
                rep(j, 3)
                {
                    int dx = x + dxy[j].first, dy = y + dxy[j].second;
                    if (stop.find({dx, dy}) == stop.end())
                    {
                        next_dp[k + (j == 0)][l + (j == 1)] += dp[k][l];
                    }
                }
            }
        }
        swap(dp, next_dp);
    }

    mint ans = 0;
    rep(i, N + 1)
    {
        rep(j, N + 1)
        {
            ans += dp[i][j];
        }
    }
    cout << ans.val() << endl;

    return 0;
}

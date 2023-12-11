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

int main()
{
    fastIO();
    int N, tmp;
    vector<int> dp(100 * 100 + 1);
    cin >> N;
    cin >> tmp;
    dp[0] = 1;
    dp[tmp] = 1;
    rep(i, N - 1)
    {
        cin >> tmp;
        rep(j, 100 * 100 + 1)
        {
            if (dp[100 * 100 - j] == 1)
            {
                dp[100 * 100 - j + tmp] = 1;
            }
        }
        dp[tmp] = 1;
    }

    int sum = accumulate(all(dp), 0);

    // logic

    cout << sum;
    cout << endl;
    return 0;
}
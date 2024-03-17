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

    int N;
    cin >> N;

    vector<int> T(N + 1), X(N + 1), A(N + 1);
    rep(i, N)
    {
        cin >> T[i + 1] >> X[i + 1] >> A[i + 1];
    }

    vector<int64> dp(N + 1);

    rep_ft(i, 1, N + 1)
    {
        int t = T[i], x = X[i], a = A[i];

        int64 max = 0;
        int scope = 0;

        if (i > 10)
        {
            scope = i - 10;
        }

        rep_ft(j, scope, i)
        {
            if (j >= 1 && dp[j] == 0)
                continue;
            if (t - T[j] >= abs(x - X[j]))
            {
                if (max < dp[j] + a)
                {
                    max = dp[j] + a;
                }
            }
        }

        dp[i] = max;
    }

    cout << *max_element(all(dp)) << endl;
    return 0;
}
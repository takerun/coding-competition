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
    // input
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W)), B(H, vector<int>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> A[i][j];
        }
    }

    rep(i, H)
    {
        rep(j, W)
        {
            cin >> B[i][j];
        }
    }

    // logic
    int ans = 100000000;
    vector<int> P, Q;
    for (int i = 0; i < H; i++)
    {
        P.emplace_back(i);
    }
    for (int i = 0; i < W; i++)
    {
        Q.emplace_back(i);
    }
    do
    {
        do
        {
            bool matched = true;
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    if (A[P[i]][Q[j]] != B[i][j])
                    {
                        matched = false;
                    }
                }
            }
            if (!matched)
            {
                continue;
            }
            int pinv = 0, qinv = 0;
            for (int i = 0; i < H; i++)
                for (int j = 0; j < H; j++)
                    if (i < j && P[i] > P[j])
                        pinv++;
            for (int i = 0; i < W; i++)
                for (int j = 0; j < W; j++)
                    if (i < j && Q[i] > Q[j])
                        qinv++;
            ans = min(ans, pinv + qinv);
        } while (next_permutation(begin(Q), end(Q)));
    } while (next_permutation(begin(P), end(P)));

    // output
    if (ans == 100000000)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }

    cout << endl;
    return 0;
}
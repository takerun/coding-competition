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
    bool ans;
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
    ans = true;
    rep(i, H)
    {
        ans &= equal(A.begin(), A.end(), B.begin(), B.end());
    }

    // output
    cout << ans;
    cout << endl;
    return 0;
}
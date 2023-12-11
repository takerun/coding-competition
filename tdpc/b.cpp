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

int A, B;
vector<int> a(A), b(B);
vector<vector<int>> dp(A, vector<int>(B));
// Return score of the best move in the given state
int dfs(int i, int j)
{
    if dp
        [i][j] != -1
                  // terminal condition
                  if (i == A && j == B) return 0;

    // try all moves
    int res = -INF;
    for (s : all_state_reached_from_given_state)
    {
        // dfs(s) return a score from opponent's view
        // update res using sum & dfs(s)
        res = max(res, sum - dfs(s));
    }
    return res;
}

int main()
{
    fastIO();

    cin >> A >> B;
    rep(i, A)
    {
        cin >> a[i];
    }
    rep(i, B)
    {
        cin >> b[i];
    }

    // logic

    cout << endl;
    return 0;
}
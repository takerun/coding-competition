// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
void Yes(bool a) { cout << (a ? "Yes" : "No") << endl; }
typedef long long int int64;

int main() {
    fastIO();
    // input
    int A, B;
    cin >> A >> B;
    vector<int> Aarr(A), Barr(B);
    for(auto &a : Aarr) cin >> a;
    for(auto &b : Barr) cin >> b;

    // logic
    vector<vector<int>> dp(A + 1, vector<int>(B + 1, -1e7));
    // return score of the best move in the given state
    auto dfs_game = [&](auto &&self, const int Ai, const int Bi) -> int {
        // exit conditions
        if(Ai == A and Bi == B) return 0;

        // use memo
        if(dp[Ai][Bi] != -1e7) return dp[Ai][Bi];

        // try all moves, select the best one
        int res = INT_MIN;
        if(Ai < A) {
            res = max(res, Aarr[Ai] - self(self, Ai + 1, Bi));
        }
        if(Bi < B) {
            res = max(res, Barr[Bi] - self(self, Ai, Bi + 1));
        }

        return dp[Ai][Bi] = res;
    };
    // usage:

    // output
    int sum = accumulate(begin(Aarr), end(Aarr), 0) +
              accumulate(begin(Barr), end(Barr), 0);
    cout << (dfs_game(dfs_game, 0, 0) + sum) / 2 << endl;
    return 0;
}
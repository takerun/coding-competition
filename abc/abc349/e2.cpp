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
    int H = 3, W = 3;
    vector<vector<int64>> Mat(H, vector<int64>(W, 0LL));
    int cti = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> Mat[i][j];
        }
    }

    // logic
    vector<vector<int>> state(H, vector<int>(W, -1));
    map<vector<vector<int>>, int64> dp;
    auto isWin = [&](const int turn) {
        for(int i = 0; i < H; i++) {
            bool isw = true;
            for(int j = 0; j < W; j++) {
                isw &= state[i][j] == turn;
            }
            if(isw) return true;
        }

        for(int i = 0; i < W; i++) {
            bool ish = true;
            for(int j = 0; j < H; j++) {
                ish &= state[j][i] == turn;
            }
            if(ish) return true;
        }

        bool isbackslash = true, isslash = true;
        for(int i = 0; i < 3; i++) {
            isbackslash &= state[i][i] == turn;
            isslash &= state[i][2 - i] == turn;
        }
        if(isbackslash) return true;
        if(isslash) return true;
        return false;
    };
    auto isEnd = [&]() {
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(state[i][j] == -1) return false;
            }
        }
        return true;
    };
    // outer variable: State state, map<state, ScoreDiff> dp
    // return the score difference of the best move in the given state
    int64 winScore = 1e12;
    auto dfs_game = [&](auto&& self, const int turn) -> int64 {
        // skip conditions, when lose
        if(isWin(turn ^ 1)) return -winScore;

        // exit conditions
        if(isEnd()) return 0;

        // use memo
        if(dp.count(state)) return dp[state];

        // try all moves
        int64 res = LLONG_MIN;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(state[i][j] != -1) continue;
                // dfs_game(s) return a score from opponent's view
                // update res using sum & dfs_game(s)
                state[i][j] = turn;
                res = max(res, Mat[i][j] - self(self, turn ^ 1));
                state[i][j] = -1;
            }
        }
        return dp[state] = res;
    };
    // usage:
    int64 ans = dfs_game(dfs_game, 0);

    // output
    cout << (ans > 0 ? "Takahashi" : "Aoki") << endl;
    return 0;
}
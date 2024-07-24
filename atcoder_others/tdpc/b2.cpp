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
    vector<int> stateA(A, -1), stateB(B, -1);
    map<vector<int>, int> dp;
    // outer variable: State state, map<state, ScoreDiff> dp
    // return the score difference of the best move in the given state
    auto dfs_game = [&](auto &&self, const int turn) -> int {
        // exit conditions
        if(stateA[A - 1] != -1 and stateB[B - 1] != -1) return 0;

        // state preprocess
        int Ai = find(begin(stateA), end(stateA), -1) - begin(stateA);
        int Bi = find(begin(stateB), end(stateB), -1) - begin(stateB);

        // use memo
        if(dp.count({Ai, Bi})) return dp[{Ai, Bi}];

        // try all moves, select the best one
        int res = INT_MIN;
        if(Ai < A) {
            stateA[Ai] = turn;
            res = max(res, Aarr[Ai] - self(self, turn ^ 1));
            stateA[Ai] = -1;
        }
        if(Bi < B) {
            stateB[Bi] = turn;
            res = max(res, Barr[Bi] - self(self, turn ^ 1));
            stateB[Bi] = -1;
        }

        return dp[{Ai, Bi}] = res;
    };

    // output
    int sum = accumulate(begin(Aarr), end(Aarr), 0) +
              accumulate(begin(Barr), end(Barr), 0);
    cout << (dfs_game(dfs_game, 0) + sum) / 2 << endl;
    return 0;
}
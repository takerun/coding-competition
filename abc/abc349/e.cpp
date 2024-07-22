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
    map<int, pair<int, int>> ctable;
    vector<int> initState;
    int cti = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> Mat[i][j];
            initState.push_back(cti);
            ctable[cti++] = {i, j};
        }
    }

    // logic
    // lines = [0row, 1row, 2row, 0col, 1col, 2col, backsla, sla]
    vector<int> winCase(8, 0);
    auto updateLines = [&](vector<int> lines, int h, int w) {
        for(int i = 0; i < H; i++) {
            if(h == i) lines[i]++;
        }
        for(int i = 0; i < W; i++) {
            if(w == i) lines[i + 3]++;
        }
        if(h == w) lines[6]++;
        if(abs(h - w) == 2) lines[7]++;
        if(h == 1 and w == 1) lines[7]++;
        return lines;
    };
    int64 winScore = 1e12;
    // return score of the best move in the given state
    auto dfs_game = [&](auto&& self, const vector<int> lines,
                        const vector<int> oplines,
                        const vector<int> state) -> int64 {
        // exit conditions
        if(state.size() == 0) return 0;

        // skip conditions
        for(int i = 0; i < 8; i++) {
            if(oplines[i] == 3) return -winScore;
        }

        // try all moves
        int64 res = LLONG_MIN;
        for(int i = 0; i < state.size(); i++) {
            // dfs_game(s) return a score from opponent's view
            // update res using sum & dfs_game(s)
            pair<int, int> cel = ctable[state[i]];
            vector<int> state_next;
            for(int j = 0; j < state.size(); j++) {
                if(state[j] == state[i]) continue;
                state_next.push_back(state[j]);
            }
            res = max(res, Mat[cel.first][cel.second] -
                               self(self, oplines,
                                    updateLines(lines, cel.first, cel.second),
                                    state_next));
        }
        return res;
    };
    // usage:
    int64 ans = dfs_game(dfs_game, winCase, winCase, initState);

    // output
    cout << (ans > 0 ? "Takahashi" : "Aoki") << endl;
    return 0;
}
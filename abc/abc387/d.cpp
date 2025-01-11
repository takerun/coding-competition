#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;
struct Direction4 {
    using D4type = int;                                         // or int64
    const D4type dh[4] = {1, 0, 0, -1}, dw[4] = {0, -1, 1, 0};  // DLRU
    const int rotation[4] = {2, 1, 3, 0};                       // RLUD
    pair<D4type, D4type> next(D4type h, D4type w, int r) {
        return {h + dh[rotation[r]], w + dw[rotation[r]]};
    }
    pair<D4type, D4type> next(D4type h, D4type w, char d) {
        int nh = h, nw = w;
        if(d == 'R') {
            nw++;
        } else if(d == 'L') {
            nw--;
        } else if(d == 'U') {
            nh--;
        } else {
            nh++;
        }
        return {nh, nw};
    }
} D4;
// usage:
// auto [nh, nw] = D4.next(h, w, 0);
// auto [nh, nw] = D4.next(h, w, 'R');

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    vector<int> start, goal;
    for(int i = 0; i < H; i++) {
        cin >> S[i];
        for(int j = 0; j < W; j++) {
            if(S[i][j] == 'S') {
                start = {i, j};
            } else if(S[i][j] == 'G') {
                goal = {i, j};
            }
        }
    }

    // logic
    vector score(H, vector(W, vector(2, -1)));  // 0:RL, 1:UD
    // define queue
    using Qsv = tuple<int, int, char, int>;  // h, w, direction, score
    queue<Qsv> Q;
    Q.push({start[0], start[1], 'R', 0});
    Q.push({start[0], start[1], 'U', 0});
    while(!Q.empty()) {
        // pop queue
        auto [h, w, d, s] = Q.front();
        Q.pop();

        // skip seen state

        // seeing logic
        int cur = 0;
        char nd[2] = {'U', 'D'};
        if(d == 'U' or d == 'D') {
            cur = 1;
            nd[0] = 'R';
            nd[1] = 'L';
        }
        if(score[h][w][cur] != -1) continue;
        score[h][w][cur] = s;
        if(h == goal[0] and w == goal[1]) break;

        // push queue
        for(int r = 0; r < 2; r++) {
            auto [nh, nw] = D4.next(h, w, nd[r]);  // next state
            // skip state
            if(nh < 0 or nh >= H or nw < 0 or nw >= W) continue;
            if(score[nh][nw][cur ^ 1] != -1) continue;
            if(S[nh][nw] == '#') continue;
            // push state
            Q.emplace(nh, nw, nd[r], s + 1);
        }
    }

    // output
    cout << max(score[goal[0]][goal[1]][0], score[goal[0]][goal[1]][1]) << endl;

    return 0;
}
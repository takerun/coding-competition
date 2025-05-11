#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int H, W;
    cin >> H >> W;
    vector<string> Mat(H);
    vector<vector<int>> E;
    for(int i = 0; i < H; i++) {
        cin >> Mat[i];
        for(int j = 0; j < W; j++) {
            if(Mat[i][j] == 'E') {
                E.push_back({i, j});
            }
        }
    }

    // logic
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
    // define seen and score
    vector<vector<bool>> seen(H,
                              vector<bool>(W, false));  // or int to color grids
    // define queue
    using Qsv = tuple<int, int, int>;  // h, w, direction
    queue<Qsv> Q;
    for(int i = 0; i < E.size(); i++) {
        Q.push({E[i][0], E[i][1], -1});
    }
    vector<string> AnsMat = Mat;
    while(!Q.empty()) {
        // pop queue
        auto [h, w, rdir] = Q.front();
        Q.pop();

        // skip seen state
        if(seen[h][w]) continue;

        // seeing logic
        seen[h][w] = true;
        // RLUD
        if(rdir == 0) {
            AnsMat[h][w] = '<';
        } else if(rdir == 1) {
            AnsMat[h][w] = '>';
        } else if(rdir == 2) {
            AnsMat[h][w] = 'v';
        } else if(rdir == 3) {
            AnsMat[h][w] = '^';
        }

        // push queue
        for(int r = 0; r < 4; r++) {
            auto [nh, nw] = D4.next(h, w, r);  // next state
            // skip state
            if(nh < 0 or nh >= H or nw < 0 or nw >= W) continue;
            if(seen[nh][nw]) continue;
            if(Mat[nh][nw] == 'E') continue;
            if(Mat[nh][nw] == '#') continue;
            // push state
            Q.emplace(nh, nw, r);
        }
    }

    // output
    for(int i = 0; i < AnsMat.size(); i++) cout << AnsMat[i] << endl;
    return 0;
}
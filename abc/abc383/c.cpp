// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int int64;
typedef unsigned long long int uint64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int H, W, D;
    cin >> H >> W >> D;
    using Qsv = tuple<int, int, int>;  // h, w, d
    queue<Qsv> Q;
    vector<string> S(H);
    for(int i = 0; i < H; i++) {
        cin >> S[i];
        for(int j = 0; j < W; j++) {
            if(S[i][j] == 'H') Q.push({i, j, D});
        }
    }

    // logic
    vector<int> dh = {0, 0, -1, 1}, dw = {1, -1, 0, 0};  // RLUD
    vector<vector<bool>> seen(H, vector<bool>(W, false));
    int seenN = 0;
    // define queue
    while(!Q.empty()) {
        // pop queue
        auto [h, w, d] = Q.front();
        Q.pop();

        // skip seen state
        if(seen[h][w]) continue;

        // seeing logic
        seen[h][w] = true;
        seenN++;
        if(d == 0) continue;

        // push queue
        for(int i = 0; i < 4; i++) {
            int nh = h + dh[i], nw = w + dw[i];  // next state
            // skip state
            if(nh < 0 or nh >= H or nw < 0 or nw >= W or S[nh][nw] == '#')
                continue;
            if(seen[nh][nw]) continue;
            // push state
            Q.push({nh, nw, d - 1});
        }
    }

    // output
    cout << seenN << endl;
    return 0;
}
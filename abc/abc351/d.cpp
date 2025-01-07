// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
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
template <class T>
inline bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    fastIO();
    // input
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(string& s : S) cin >> s;

    // logic
    vector<int> dh = {0, 0, -1, 1}, dw = {1, -1, 0, 0};  // RLUD
    int mx = 0;
    // set '!' near mag
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '#') {
                for(int r = 0; r < 4; r++) {
                    auto [nh, nw] = D4.next(i, j, r);
                    if(nh < 0 or nh >= H or nw < 0 or nw >= W) continue;
                    if(S[nh][nw] == '.') {
                        S[nh][nw] = '!';
                        mx = 1;
                    }
                }
            }
        }
    }
    vector<vector<int>> seen(H, vector<int>(W, -1));
    // define queue
    using Qsv = tuple<int, int>;  // h, w
    queue<Qsv> Q;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '.' and seen[i][j] == -1) {
                int mxi = 0;
                Q.push({i, j});
                while(!Q.empty()) {
                    // pop queue
                    auto [h, w] = Q.front();
                    Q.pop();

                    // skip seen state
                    if(seen[h][w] == i * W + j) continue;

                    // seeing logic
                    seen[h][w] = i * W + j;
                    mxi++;
                    if(S[h][w] == '!') continue;

                    // push queue
                    for(int r = 0; r < 4; r++) {
                        auto [nh, nw] = D4.next(h, w, r);  // next state
                        // skip state
                        if(nh < 0 or nh >= H or nw < 0 or nw >= W) continue;
                        if(seen[nh][nw] == i * W + j) continue;
                        // push state
                        Q.emplace(nh, nw);
                    }
                }
                chmax(mx, mxi);
            }
        }
    }

    // output
    cout << mx << endl;
    return 0;
}
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int int64;
template <class T>
inline T ceil_x_yth(T x, T y) {
    // x/y: x(divident), y(divisor)
    return x >= 0 ? ((x + y - 1) / y) : (x / y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int64 H, W, X, P, Q;
    cin >> H >> W >> X >> P >> Q, P--, Q--;
    vector<vector<int64>> Mat(H, vector<int64>(W, 0LL));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> Mat[i][j];
        }
    }

    // logic
    vector<int> dh = {0, 0, -1, 1}, dw = {1, -1, 0, 0};  // RLUD
    using Qsv = tuple<int64, int64, int64>;              // strength, h, w
    auto bfs = [&](Qsv start) -> int64 {
        // define seen and score
        vector<vector<bool>> seen(H, vector<bool>(W, false));
        // define queue
        priority_queue<Qsv, vector<Qsv>, greater<Qsv>> Q;
        auto [strength, starth, startw] = start;
        Q.push({0, starth, startw});
        while(!Q.empty()) {
            // pop queue
            auto [s, h, w] = Q.top();
            Q.pop();

            // skip seen state
            if(seen[h][w]) continue;

            // seeing logic
            seen[h][w] = true;
            if(s >= ceil_x_yth(strength, X)) break;
            strength += s;

            // push queue
            for(int i = 0; i < 4; i++) {
                int nh = h + dh[i], nw = w + dw[i];  // next state
                // skip state
                if(nh < 0 or nh >= H or nw < 0 or nw >= W) continue;
                if(seen[nh][nw]) continue;
                // push state
                Q.push({Mat[nh][nw], nh, nw});
            }
        }
        return strength;
    };

    // output
    cout << bfs({Mat[P][Q], P, Q}) << endl;
    return 0;
}
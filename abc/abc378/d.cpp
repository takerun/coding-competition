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
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    for(int i = 0; i < H; i++) {
        cin >> S[i];
    }

    // logic
    vector<int> dh = {0, 0, -1, 1}, dw = {1, -1, 0, 0};  // RLUD
    vector<vector<bool>> State(H, vector<bool>(W, false));
    auto dfs = [&](auto&& self, const int h, const int w,
                   const int count) -> int64 {
        // exit conditions
        if(count == K) return 1;

        // try all moves
        int64 sum = 0LL;
        for(int i = 0; i < 4; i++) {
            int nh = h + dh[i];
            int nw = w + dw[i];
            if(nh < 0 || nw < 0 || nh >= H || nw >= W || S[nh][nw] == '#')
                continue;
            if(State[nh][nw] == true) continue;

            State[nh][nw] = true;
            sum += self(self, nh, nw, count + 1);
            State[nh][nw] = false;
        }
        return sum;
    };

    int64 ans = 0LL;
    for(int hi = 0; hi < H; hi++) {
        for(int wi = 0; wi < W; wi++) {
            if(S[hi][wi] == '#') continue;
            State[hi][wi] = true;
            ans += dfs(dfs, hi, wi, 0);
            State[hi][wi] = false;
        }
    }

    // output
    cout << ans << endl;
    return 0;
}
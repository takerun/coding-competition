#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
typedef long long int int64;

int main() {
    fastIO();
    // input
    int H, W, N;
    cin >> H >> W >> N;

    // logic
    const string rotation = "URDL";
    map<char, const int> dh = {{'R', 0}, {'L', 0}, {'U', -1}, {'D', 1}},
                         dw = {{'R', 1}, {'L', -1}, {'U', 0}, {'D', 0}};
    int dc = 0, h = 0, w = 0;
    vector<vector<bool>> X(H, vector<bool>(W, false));
    for(int _ = 0; _ < N; _++) {
        h = (h % H + H) % H;
        w = (w % W + W) % W;
        if(X[h][w]) {
            // 黒
            X[h][w] = false;
            dc = (--dc % 4 + 4) % 4;
        } else {
            // 白
            X[h][w] = true;
            dc = (++dc % 4 + 4) % 4;
        }
        h += dh[rotation[dc]];
        w += dw[rotation[dc]];
    }

    // output
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(X[i][j]) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
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
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> Mat(H, vector<int>(W, 0));
    vector<queue<vector<int>>> Qs(Y, queue<vector<int>>());
    vector<vector<bool>> Done(H, vector<bool>(W, false));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> Mat[i][j];
            Mat[i][j]--;
            if(i == 0 or i == H - 1 or j == 0 or j == W - 1) {
                if(Mat[i][j] < Y) {
                    Qs[Mat[i][j]].push({i, j});
                }
                Done[i][j] = true;
            }
        }
    }

    // logic
    vector<int> dh = {0, 0, -1, 1}, dw = {1, -1, 0, 0};  // RLUD
    int res = H * W;
    for(int y = 0; y < Y; y++) {
        while(!Qs[y].empty()) {
            // pop queue
            vector<int> q = Qs[y].front();
            Qs[y].pop();
            res--;

            // skip state

            // evaluate state
            for(int i = 0; i < 4; i++) {
                // next state
                vector<int> nq = {q[0] + dh[i], q[1] + dw[i]};
                // push state
                if(nq[0] >= 0 and nq[0] < H and nq[1] >= 0 and nq[1] < W and
                   !Done[nq[0]][nq[1]]) {
                    if(Mat[nq[0]][nq[1]] <= y) {
                        Qs[y].push(nq);
                    } else if(Mat[nq[0]][nq[1]] <= Y) {
                        Qs[Mat[nq[0]][nq[1]]].push(nq);
                    }

                    Done[nq[0]][nq[1]] = true;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
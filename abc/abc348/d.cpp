// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
typedef long long int int64;

vector<int> dh = {0, 0, -1, 1}, dw = {1, -1, 0, 0};  // RLUD

int main() {
    fastIO();
    // input
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    vector<int> S;
    for(int i = 0; i < H; i++) {
        cin >> A[i];
        for(int j = 0; j < W; j++) {
            if(A[i][j] == 'S') {
                S = {i, j};
            }
        }
    }
    int N;
    cin >> N;
    vector<vector<int>> E(H, vector<int>(W, 0));
    for(int i = 0; i < N; i++) {
        int r, c, e;
        cin >> r >> c >> e;
        r--, c--;
        E[r][c] = e;
    }

    // logic
    // define Value & initail State
    vector<vector<int>> Val(H, vector<int>(W, -1));
    Val[S[0]][S[1]] = max(E[S[0]][S[1]], 0);
    // define queue
    queue<vector<int>> Q;
    Q.push(S);
    while(!Q.empty()) {
        // pop queue
        vector<int> q = Q.front();
        Q.pop();

        // evaluate state
        for(int i = 0; i < 4; i++) {
            // next state
            int nextH = q[0] + dh[i], nextW = q[1] + dw[i];
            if(nextH < 0 or nextH >= H or nextW < 0 or nextW >= W or
               A[nextH][nextW] == '#')
                continue;

            // push state
            if(Val[nextH][nextW] < Val[q[0]][q[1]] - 1) {
                if(A[nextH][nextW] == 'T') {
                    cout << "Yes" << endl;
                    return 0;
                }

                Val[nextH][nextW] = max(Val[q[0]][q[1]] - 1, E[nextH][nextW]);
                Q.push({nextH, nextW});
            }
        }
    }

    // output
    cout << "No" << endl;
    return 0;
}
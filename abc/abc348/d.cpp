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

// answer2

// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
// #include <bits/stdc++.h>
// using namespace std;

// #define fastIO()                      \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(nullptr);                 \
//     cout.tie(nullptr)
// #define endl "\n"
// typedef long long int int64;
// void Yes(bool a) { cout << (a ? "Yes" : "No") << endl; }

// int main() {
//     fastIO();
//     // input
//     int H, W;
//     cin >> H >> W;
//     vector<string> A(H);
//     vector<int> S, T;
//     for(int i = 0; i < H; i++) {
//         cin >> A[i];
//         for(int j = 0; j < W; j++) {
//             if(A[i][j] == 'S') {
//                 S = {i, j};
//             } else if(A[i][j] == 'T') {
//                 T = {i, j};
//             }
//         }
//     }
//     int N;
//     cin >> N;
//     vector<vector<int>> E(H, vector<int>(W, 0));
//     vector<int> R(N), C(N);
//     for(int i = 0; i < N; i++) {
//         int r, c, e;
//         cin >> r >> c >> e;
//         r--, c--;
//         E[r][c] = e;
//         R[i] = r;
//         C[i] = c;
//     }

//     // logic
//     vector<int> dh = {0, 0, -1, 1}, dw = {1, -1, 0, 0};  // RLUD
//     // outer variable: int H, W;
//     auto bfs_in = [&](vector<int>& initS,
//                       const int energy) -> vector<vector<int>> {
//         // define Value
//         vector<vector<int>> Val(H, vector<int>(W, INT_MAX));
//         Val[initS[0]][initS[1]] = 0;
//         // define queue
//         queue<vector<int>> Q;
//         Q.push(initS);
//         while(!Q.empty()) {
//             // pop queue
//             vector<int> q = Q.front();
//             Q.pop();

//             // skip state

//             // evaluate state
//             if(Val[q[0]][q[1]] + 1 > energy) continue;

//             for(int i = 0; i < 4; i++) {
//                 int nextH = q[0] + dh[i], nextW = q[1] + dw[i];
//                 if(nextH >= 0 && nextH < H && nextW >= 0 && nextW < W &&
//                    A[nextH][nextW] != '#' && Val[nextH][nextW] == INT_MAX) {
//                     Val[nextH][nextW] = Val[q[0]][q[1]] + 1;
//                     // push state
//                     if(Val[nextH][nextW] < energy)
//                         Q.emplace(vector<int>{nextH, nextW});
//                 }
//             }
//         }
//         return Val;
//     };

//     // outer variable: E, S, H, W, T, R, C;
//     auto bfs_out = [&]() -> bool {
//         if(E[S[0]][S[1]] == 0) return false;
//         // define Value
//         vector<vector<bool>> Done(H, vector<bool>(W, false));
//         // define queue
//         queue<vector<int>> Q;
//         Q.push(S);
//         while(!Q.empty()) {
//             // pop queue
//             vector<int> q = Q.front();
//             Q.pop();

//             // skip state
//             if(Done[q[0]][q[1]]) continue;

//             // evaluate state
//             vector<vector<int>> Val = bfs_in(q, E[q[0]][q[1]]);
//             Done[q[0]][q[1]] = true;

//             if(Val[T[0]][T[1]] != INT_MAX) return true;

//             for(int i = 0; i < R.size(); i++) {
//                 if(!Done[R[i]][C[i]] && Val[R[i]][C[i]] != INT_MAX &&
//                    E[R[i]][C[i]] > 0) {
//                     Q.push({R[i], C[i]});
//                 }
//             }
//         }
//         return false;
//     };

//     // output
//     Yes(bfs_out());
//     return 0;
// }
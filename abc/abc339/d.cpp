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

int main() {
    fastIO();
    // input
    int N;
    cin >> N;
    vector<string> S(N);
    for(string &s : S) cin >> s;

    // logic
    const string rotation = "URDL";
    map<char, const int> dh = {{'R', 0}, {'L', 0}, {'U', -1}, {'D', 1}},
                         dw = {{'R', 1}, {'L', -1}, {'U', 0}, {'D', 0}};
    vector State(N, vector(N, vector(N, vector(N, INT_MAX))));
    queue<vector<int>> Q;
    vector<int> init;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(S[i][j] == 'P') {
                init.emplace_back(i);
                init.emplace_back(j);
            }
        }
    }
    State[init[0]][init[1]][init[2]][init[3]] = 0;
    Q.push(init);
    while(!Q.empty()) {
        vector<int> q = Q.front();
        Q.pop();

        int h1 = q[0], w1 = q[1], h2 = q[2], w2 = q[3];
        for(int i = 0; i < 4; i++) {
            int d = rotation[i];
            int h1next = h1 + dh[d], w1next = w1 + dw[d], h2next = h2 + dh[d],
                w2next = w2 + dw[d];
            if(h1next < 0 || h1next >= N || w1next < 0 || w1next >= N ||
               S[h1next][w1next] == '#') {
                h1next = h1, w1next = w1;
            }
            if(h2next < 0 || h2next >= N || w2next < 0 || w2next >= N ||
               S[h2next][w2next] == '#') {
                h2next = h2, w2next = w2;
            }
            if(State[h1next][w1next][h2next][w2next] == INT_MAX) {
                State[h1next][w1next][h2next][w2next] =
                    State[h1][w1][h2][w2] + 1;
                Q.push({h1next, w1next, h2next, w2next});
            }
        }
    }

    // output
    int mn = INT_MAX;  // 2e9
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            mn = min(mn, State[i][j][i][j]);
        }
    }
    cout << (mn == INT_MAX ? -1 : mn);
    cout << endl;
    return 0;
}

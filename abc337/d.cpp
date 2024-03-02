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
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> A(H);
    for(string &a : A) cin >> a;

    // logic
    int ans = INT_MAX;  // 2e9
    for(int i = 0; i < H; i++) {
        vector<int> cumlo(W + 1, 0), cumlx(W + 1, 0), cumldot(W + 1, 0);
        for(int j = 0; j < W; j++) {
            int o = 0, x = 0, dot = 0;
            if(A[i][j] == 'o') {
                o = 1;
            } else if(A[i][j] == 'x') {
                x = 1;
            } else {
                dot = 1;
            }
            cumlo[j + 1] = cumlo[j] + o;
            cumlx[j + 1] = cumlx[j] + x;
            cumldot[j + 1] = cumldot[j] + dot;
        }
        for(int j = 0; j < W - K + 1; j++) {
            int xx = cumlx[j + K] - cumlx[j];
            if(xx > 0) {
                continue;
            }

            int oo = cumlo[j + K] - cumlo[j];
            int ddot = cumldot[j + K] - cumldot[j];
            ans = min(ans, ddot);
        }
    }
    for(int i = 0; i < W; i++) {
        vector<int> cumlo(H + 1, 0), cumlx(H + 1, 0), cumldot(H + 1, 0);
        for(int j = 0; j < H; j++) {
            int o = 0, x = 0, dot = 0;
            if(A[j][i] == 'o') {
                o = 1;
            } else if(A[j][i] == 'x') {
                x = 1;
            } else {
                dot = 1;
            }
            cumlo[j + 1] = cumlo[j] + o;
            cumlx[j + 1] = cumlx[j] + x;
            cumldot[j + 1] = cumldot[j] + dot;
        }
        for(int j = 0; j < H - K + 1; j++) {
            int xx = cumlx[j + K] - cumlx[j];
            if(xx > 0) {
                continue;
            }

            int oo = cumlo[j + K] - cumlo[j];
            int ddot = cumldot[j + K] - cumldot[j];
            ans = min(ans, ddot);
        }
    }

    // output
    if(ans == INT_MAX) {
        cout << -1;
    } else {
        cout << ans;
    }

    cout << endl;
    return 0;
}
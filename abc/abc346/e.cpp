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
    int64 H, W, M;
    cin >> H >> W >> M;
    vector<int64> T(M, 0), A(M, 0), X(M, 0);
    for(int64 i = 0; i < M; i++) {
        cin >> T[i] >> A[i] >> X[i];
    }

    // logic
    vector<int64> color(2e5 + 1, 0);
    set<int64> usedH, usedW;
    for(int64 i = M - 1; i >= 0; i--) {
        if(T[i] == 1) {
            if(usedH.count(A[i]) == 0) {
                color[X[i]] += W - (int64)usedW.size();
                usedH.insert(A[i]);
            }
        } else {
            if(usedW.count(A[i]) == 0) {
                color[X[i]] += H - (int64)usedH.size();
                usedW.insert(A[i]);
            }
        }
    }

    // output
    int64 sum = 0, cnt = 0;
    for(int64 i = 0; i < 2e5 + 1; i++) {
        sum += color[i];
        if(color[i] != 0) {
            cnt++;
        }
    }
    if(color[0] == 0) {
        if(H * W - sum == 0) {
            cout << cnt << endl;
        } else {
            cout << cnt + 1 << endl;
            cout << 0 << " " << color[0] + H * W - sum << endl;
        }
    } else {
        cout << cnt << endl;
        cout << 0 << " " << color[0] + H * W - sum << endl;
    }

    for(int64 i = 1; i < 2e5 + 1; i++) {
        if(color[i] == 0) continue;
        cout << i << " " << color[i] << endl;
    }
    cout << endl;
    return 0;
}
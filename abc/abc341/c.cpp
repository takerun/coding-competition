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
    string T;
    cin >> H >> W >> N;
    cin >> T;
    // string dt = "LRUD";
    vector<int> dh = {0, 0, -1, 1};
    vector<int> dw = {-1, 1, 0, 0};
    vector<string> S(H, "");
    for(string &s : S) cin >> s;

    // logic
    int ans = 0;
    for(int i = 1; i < H - 1; i++) {
        for(int j = 1; j < W - 1; j++) {
            if(S[i][j] == '.') {
                int di = i, dj = j;
                bool rs = true;
                for(int i = 0; i < N; i++) {
                    if(T[i] == 'L') {
                        di += dh[0];
                        dj += dw[0];
                    } else if(T[i] == 'R') {
                        di += dh[1];
                        dj += dw[1];
                    } else if(T[i] == 'U') {
                        di += dh[2];
                        dj += dw[2];
                    } else {
                        di += dh[3];
                        dj += dw[3];
                    }
                    if(S[di][dj] == '#') {
                        rs = false;
                        break;
                    }
                }
                if(rs) {
                    ans++;
                }
            }
        }
    }

    // output
    cout << ans;
    cout << endl;
    return 0;
}
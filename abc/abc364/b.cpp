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
    int H, W, si, sj;
    cin >> H >> W >> si >> sj;
    si--, sj--;
    vector<string> C(H);
    for(auto &a : C) cin >> a;
    string X;
    cin >> X;

    // logic
    int h = si, w = sj, hn, wn;
    vector<int> dh = {0, 0, -1, 1}, dw = {1, -1, 0, 0};  // RLUD
    for(int i = 0; i < X.size(); i++) {
        if(X[i] == 'L') {
            hn = h + dh[1];
            wn = w + dw[1];
        } else if(X[i] == 'R') {
            hn = h + dh[0];
            wn = w + dw[0];
        } else if(X[i] == 'U') {
            hn = h + dh[2];
            wn = w + dw[2];
        } else {
            hn = h + dh[3];
            wn = w + dw[3];
        }
        if(hn >= 0 and hn < H and wn >= 0 and wn < W and C[hn][wn] == '.') {
            h = hn;
            w = wn;
        }
    }

    // output
    cout << h + 1 << " " << w + 1 << endl;
    return 0;
}
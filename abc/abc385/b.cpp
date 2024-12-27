// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int int64;
typedef unsigned long long int uint64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int H, W, X, Y;
    cin >> H >> W >> X >> Y, X--, Y--;
    vector<string> S(H);
    for(auto &a : S) cin >> a;
    string T;
    cin >> T;

    // logic
    map<char, int> m = {{'R', 0}, {'L', 1}, {'U', 2}, {'D', 3}};
    vector<int> dh = {0, 0, -1, 1}, dw = {1, -1, 0, 0};  // RLUD
    set<pair<int, int>> seen;
    for(int i = 0; i < T.size(); i++) {
        char t = T[i];
        int nh = X + dh[m[t]], nw = Y + dw[m[t]];
        if(S[nh][nw] == '#') continue;
        if(S[nh][nw] == '@') seen.insert({nh, nw});
        X = nh, Y = nw;
    }

    // output
    cout << X + 1 << " " << Y + 1 << " " << seen.size() << endl;
    return 0;
}
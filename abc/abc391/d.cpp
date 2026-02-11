#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;
template <class T>
inline bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int N, W;
    cin >> N >> W;
    vector<vector<pair<int64, int>>> Box(W);  // value: height, Bi

    int64 x, y;
    for(int i = 0; i < N; i++) {
        cin >> x >> y, x--, y--;
        Box[x].emplace_back(y, i);
    }
    int64 mn = numeric_limits<int64>::max();
    // 9e18
    for(int i = 0; i < W; i++) {
        if(Box[i].size() == 0) {
            mn = 0LL;
            break;
        }
        chmin(mn, (int64)Box[i].size());
        sort(begin(Box[i]), end(Box[i]));
    }

    // logic
    // 各ブロックの消える瞬間をシュミレートしておく
    vector<int64> vanish(N, 1e10);
    int64 time = 0LL;
    for(int mm = 0; mm < mn; mm++) {
        int64 mx = numeric_limits<int64>::min();  // -9e18
        for(int i = 0; i < W; i++) {
            chmax(mx, max(Box[i][mm].first - time, 0LL));
        }
        time += mx;
        time++;
        for(int i = 0; i < W; i++) {
            vanish[Box[i][mm].second] = time;
        }
    }

    // queue start
    int Q;
    cin >> Q;
    int64 t, a;
    for(int i = 0; i < Q; i++) {
        cin >> t >> a, t, a--;
        cout << (vanish[a] > t ? "Yes" : "No") << endl;
        // cout << vanish[a] << endl;
    }

    // output
    // for(int i = 0; i < Box.size(); i++)
    //     for(int j = 0; j < Box[i].size(); j++)
    //         cout << Box[i][j].first << " " << Box[i][j].second
    //              << endlif(j == Box[i].size() - 1);
    return 0;
}

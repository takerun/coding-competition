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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int64 N, M;
    cin >> N >> M;

    // logic
    vector<int64> Llimit(M, -1LL);
    for(int i = 0; i < N; i++) {
        int64 l, r;
        cin >> l >> r, l--, r--;
        chmax(Llimit[r], l);
    }
    for(int r = 1; r < M; r++) chmax(Llimit[r], Llimit[r - 1]);

    int64 ans = 0LL;
    for(int64 r = 0; r < M; r++) {
        ans += r - Llimit[r];
    }
    // output
    cout << ans << endl;
    return 0;
}
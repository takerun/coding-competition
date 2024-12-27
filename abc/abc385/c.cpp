// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int int64;
typedef unsigned long long int uint64;
template <class T>
inline bool chmax(T &a, T b) {
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
    int N;
    cin >> N;
    vector<int> H(N, 0);
    for(auto &a : H) cin >> a;

    // logic
    int ans = 1;
    for(int i = 1; i < N; i++) {
        for(int t = 0; t < i; t++) {
            int cur = H[t], ians = 1;
            for(int j = t + i; j < N; j += i) {
                if(H[j] == cur) {
                    ians++;
                } else {
                    chmax(ans, ians);
                    cur = H[j], ians = 1;
                }
            }
            chmax(ans, ians);
        }
    }

    // output
    cout << ans << endl;
    return 0;
}
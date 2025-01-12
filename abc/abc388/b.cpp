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
    int N, D;
    cin >> N >> D;
    vector<int64> T(N, 0), L(N, 0);
    for(int i = 0; i < T.size(); i++) cin >> T[i] >> L[i];

    // logic
    for(int i = 0; i < N; i++) {
        L[i] = L[i] * T[i];
    }
    for(int i = 0; i < D; i++) {
        int64 mx = 0;
        for(int i = 0; i < N; i++) {
            L[i] += T[i];
            chmax(mx, L[i]);
        }
        cout << mx << endl;
    }

    // output

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;
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
    int N, M;
    cin >> N >> M;
    vector<int64> C(N, 0LL);
    for(int i = 0; i < C.size(); i++) cin >> C[i];

    int K, a;
    vector<vector<bool>> hasAni(N, vector<bool>(M, false));  // 園, 動物
    for(int i = 0; i < M; i++) {
        cin >> K;
        for(int j = 0; j < K; j++) {
            cin >> a, a--;
            hasAni[a][i] = true;
        }
    }

    // logic
    int64 mn = numeric_limits<int64>::max();

    int Nbit = N;
    vector<int> bit(Nbit);
    for(int i = 0; i < (1 << Nbit); i++) {
        int pow = 1;
        for(int digit = 0; digit < Nbit; digit++)
            bit[digit] = (i / pow) % 2, pow <<= 1;
        // logic
        vector<int> canSee(M, 0);
        for(int j = 0; j < bit.size(); j++) {
            if(bit[j] == 1) {
                for(int k = 0; k < hasAni[j].size(); k++) {
                    canSee[k] += hasAni[j][k];
                }
            }
        }
        bool cS = true, bi = true;
        for(int k = 0; k < M; k++) {
            cS = cS and canSee[k];
            if(canSee[k] < 2) bi = false;
        }
        if(cS) {
            int64 cost = 0LL;
            for(int j = 0; j < bit.size(); j++) {
                // cout << bit[j] << " ";
                if(bit[j] == 1) {
                    cost += C[j];
                }
            }
            if(bi == false) {
                cost *= 2;
            }
            // cout << cost << endl;
            chmin(mn, cost);
        }
    }

    // output
    cout << mn << endl;
    return 0;
}
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
// https://atcoder.github.io/ac-library/production/document_en/dsu.html
#include <atcoder/dsu>
using dsu = atcoder::dsu;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int H, W;
    cin >> H >> W;
    int HW = H * W;
    vector<int64> A(HW, int64{0});
    for(int i = 0; i < HW; i++) {
        cin >> A[i];
    }

    // logic
    int64 ans = int64{0};
    int Nbit = HW;
    vector<int> bit(Nbit);
    for(int i = 0; i < (1 << Nbit); i++) {  // 10^6
        int pow = 1;
        for(int digit = 0; digit < Nbit; digit++)
            bit[digit] = (i / pow) % 2, pow <<= 1;

        // logic: use bit
        // check if the bit meets domino
        dsu d(Nbit);
        for(int j = 0; j < Nbit; j++) {
            if(bit[j] == 1) continue;
            int h = j / W, w = j % W;
            // check right
            if(w + 1 < W && bit[j + 1] == 0) {
                d.merge(j, j + 1);
            }
            // check down
            if(h + 1 < H && bit[j + W] == 0) {
                d.merge(j, j + W);
            }
        }

        bool isEven = true;
        vector<vector<int>> dg = d.groups();
        for(int j = 0; j < dg.size(); j++) {
            if(dg[j].size() % 2 == 1 and bit[dg[j][0]] == 0) {
                isEven = false;
                break;
            }
        }

        // cout << d.groups().size() << endl;
        // for(int l = 0; l < d.groups().size(); l++) {
        //     for(int m = 0; m < d.groups()[l].size(); m++) {
        //         cout << d.groups()[l][m] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << isEven << endl;
        if(!isEven) {
            continue;  // skip this bit
        }
        // mul xor
        int64 mulxor = int64{0};
        for(int k = 0; k < bit.size(); k++) {  // 10^1
            if(bit[k] == 1) mulxor ^= A[k];
        }

        chmax(ans, mulxor);
    }

    // output
    cout << ans << endl;
    return 0;
}
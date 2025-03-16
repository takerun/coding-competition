#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int N, Q;
    cin >> N >> Q;
    int op, p, h;  // p:はと, h:す

    // logic
    int over2 = 0;
    vector<int> P(N, 0);
    for(int i = 0; i < N; i++) P[i] = i;
    vector<int> H(N, 1);
    for(int i = 0; i < Q; i++) {
        cin >> op;
        if(op == 1) {
            cin >> p >> h, p--, h--;
            // update
            H[P[p]]--;  // P[p]: cur H
            if(H[P[p]] == 1) over2--;
            P[p] = h;
            H[P[p]]++;
            if(H[P[p]] == 2) over2++;
        } else {
            cout << over2 << endl;
        }
    }

    // output
    return 0;
}
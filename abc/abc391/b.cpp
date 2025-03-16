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
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for(int i = 0; i < S.size(); i++) cin >> S[i];
    vector<string> T(M);
    for(int i = 0; i < T.size(); i++) cin >> T[i];

    // logic
    // S[i][j], T[k][l]
    for(int i = 0; i < N - M + 1; i++) {
        for(int j = 0; j < N - M + 1; j++) {
            bool is = true;
            for(int k = 0; k < M; k++) {
                for(int l = 0; l < M; l++) {
                    is &= (S[i + k][j + l] == T[k][l]);
                }
            }
            if(is) {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }

    // output
    return 0;
}
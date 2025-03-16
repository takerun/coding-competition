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
    int N;
    int64 K;  // transform count
    cin >> N >> K;
    int MAX_DOUBLING = 64;
    vector<vector<int>> next(MAX_DOUBLING, vector<int>(N));
    for(int i = 0; i < N; i++) cin >> next[0][i], next[0][i]--;
    vector<int> A(N, 0);
    for(int i = 0; i < A.size(); i++) cin >> A[i];

    // logic
    for(int d = 0; d + 1 < MAX_DOUBLING; d++) {
        for(int i = 0; i < N; i++) {
            next[d + 1][i] = next[d][next[d][i]];
        }
    }
    for(int i = 0; i < N; i++) {
        int transformed_i = i;
        for(int d = 0; d < MAX_DOUBLING; ++d) {
            if(K & (1LL << d)) transformed_i = next[d][transformed_i];
        }
        cout << A[transformed_i] << endlif(i == N - 1);
    }

    // output
    return 0;
}
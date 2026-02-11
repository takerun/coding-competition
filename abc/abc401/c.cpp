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
    int64 N, K;
    cin >> N >> K;

    // logic
    vector<int64> A(N + 1, 1LL);
    int64 sm = K, mod = 1e9;
    for(int64 i = K; i <= N; i++) {
        A[i] = sm;
        sm = sm + A[i] - A[i - K];
        sm = (sm % mod + mod) % mod;
    }

    // output
    cout << A[N] << endl;
    return 0;
}
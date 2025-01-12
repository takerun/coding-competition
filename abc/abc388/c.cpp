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
    cin >> N;
    vector<int64> A(N, 0);
    for(int i = 0; i < A.size(); i++) cin >> A[i];

    // logic
    int64 sm = 0LL;
    for(int i = 0; i < N; i++) {
        int64 Ai = A[i], Hi = Ai / 2;
        auto uit = upper_bound(begin(A), end(A), Hi);
        sm += uit - begin(A);
    }

    // output
    cout << sm << endl;
    return 0;
}
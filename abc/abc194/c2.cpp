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
    vector<int64> A(N, 0LL), cml(N + 1, 0LL);
    int64 AAsum = 0LL;
    for(int i = 0; i < A.size(); i++) {
        cin >> A[i];
        AAsum += A[i] * A[i] * (N - 1);
        cml[i + 1] = cml[i] + A[i];
    }

    // logic
    for(int i = 0; i < N - 1; i++) {
        AAsum -= 2LL * A[i] * (cml[N] - cml[i + 1]);
    }

    // output
    cout << AAsum << endl;
    return 0;
}
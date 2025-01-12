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
    int64 N;
    cin >> N;
    vector<int64> A(N, 0LL), off(N + 1, 0LL);
    for(int i = 0; i < A.size(); i++) cin >> A[i];

    // logic
    int64 offset = 0LL;
    for(int i = 0; i < N; i++) {
        offset += off[i];
        int64 diff = min(A[i] + offset, N - i - 1);
        A[i] = A[i] + offset - diff;
        if(diff > 0) {
            off[i + 1] += 1;
            off[i + diff + 1] += -1;
        }
    }

    // output
    for(int i = 0; i < A.size(); i++) cout << A[i] << endlif(i == A.size() - 1);
    return 0;
}
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
    vector<int64> A(N, int64{0});
    for(int i = 0; i < A.size(); i++) cin >> A[i];

    // logic
    int64 bisum{0};
    for(int i = 0; i < A.size(); i++) bisum += A[i] * A[i];
    int64 sum = accumulate(begin(A), end(A), int64{0});

    // output
    cout << (sum * sum - bisum) / 2 << endl;
    return 0;
}
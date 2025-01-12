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
    vector<int64> A(N, 0);
    for(int i = 0; i < A.size(); i++) cin >> A[i];

    // logic
    auto f = [&](int64 k) {
        for(int64 i = 0; i < k; i++) {
            if(A[i] > A[N - k + i] / 2) return false;
        }
        return true;
    };
    int64 ng = N / 2 + 1, ok = 0;  // 反転も可能
    while(abs(ok - ng) > 1) {
        int64 mid = (ok + ng) / 2;
        if(f(mid))
            ok = mid;
        else
            ng = mid;
    }

    // output
    cout << ok << endl;
    return 0;
}
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
    vector<int> A(N, 0);
    for(int i = 0; i < A.size(); i++) cin >> A[i];

    // logic
    bool rtn = true;
    for(int i = 0; i < N - 1; i++) {
        rtn &= A[i] < A[i + 1];
    }

    // output
    cout << (rtn ? "Yes" : "No") << endl;
    return 0;
}
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
typedef long long int int64;

int main() {
    fastIO();
    // input
    int N, Q;
    cin >> N >> Q;

    // logic
    vector<int> A(N, 1);
    for(int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        t--;
        if(A[t] == 0) {
            A[t] = 1;
        } else {
            A[t] = 0;
        }
    }

    // output
    cout << accumulate(begin(A), end(A), 0);
    cout << endl;
    return 0;
}
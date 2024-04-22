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
    int N, K;
    cin >> N >> K;
    vector<int> A(N, 0);
    for(int &a : A) cin >> a;

    // logic
    for(int i = 0; i < N; i++) {
        if(A[i] % K == 0) {
            cout << A[i] / K << " ";
        }
    }

    // output
    cout << endl;
    return 0;
}
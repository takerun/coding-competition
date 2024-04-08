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
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for(int &a : A) cin >> a;

    // logic
    for(int i = 0; i < N - 1; i++) {
        // logic
        cout << A[i] * A[i + 1] << " ";
    }

    // output
    cout << endl;
    return 0;
}
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
void Yes(bool a) { cout << (a ? "Yes" : "No") << endl; }
typedef long long int int64;

int main() {
    fastIO();
    // input
    int N, K;
    cin >> N >> K;
    vector<int> A(N, 0);
    for(auto &a : A) cin >> a;

    // logic
    for(int i = N - K; i < N + N - K; i++) {
        cout << A[i % N] << " ";
    }

    // output
    cout << endl;
    return 0;
}
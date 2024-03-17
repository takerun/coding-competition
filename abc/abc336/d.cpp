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
    vector<int> R(N), L(N);
    R[0] = 1;
    for(int i = 0; i < N - 1; i++) {
        R[i + 1] = min(R[i] + 1, A[i + 1]);
    }
    L[N - 1] = 1;
    for(int i = N - 1; i > 0; i--) {
        L[i - 1] = min(L[i] + 1, A[i - 1]);
    }
    int mx = INT_MIN;  // -2e9
    for(int i = 0; i < N; i++) {
        mx = max(mx, min(R[i], L[i]));
    }

    // output
    cout << mx;
    cout << endl;
    return 0;
}

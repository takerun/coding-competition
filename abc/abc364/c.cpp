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
    int64 N, X, Y;
    cin >> N >> X >> Y;
    vector<int64> A(N, 0);
    for(auto &a : A) cin >> a;
    vector<int64> B(N, 0);
    for(auto &a : B) cin >> a;

    // logic
    sort(begin(A), end(A), greater<int>());
    sort(begin(B), end(B), greater<int>());
    int64 cumA = 0, cumB = 0;
    for(int i = 0; i < N; i++) {
        cumA += A[i];
        cumB += B[i];
        if(cumA > X or cumB > Y) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    // output
    cout << N << endl;
    return 0;
}
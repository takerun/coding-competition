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
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for(auto &a : A) cin >> a;

    // logic
    int ans = 0;
    sort(begin(A), end(A), greater<int>());
    while(A[1] != 0) {
        A[0]--, A[1]--, ans++;
        sort(begin(A), end(A), greater<int>());
    }

    // output
    cout << ans << endl;
    return 0;
}
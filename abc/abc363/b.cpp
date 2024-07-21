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
    int N, T, P;
    cin >> N >> T >> P;
    vector<int> L(N, 0);
    for(auto &a : L) cin >> a;

    // logic
    sort(begin(L), end(L), greater<int>());
    int ans = T - L[P - 1];

    // output
    if(ans <= 0) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
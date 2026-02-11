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
    int N, A;
    cin >> N >> A;
    vector<int> T(N, 0);
    for(auto &t : T) cin >> t;

    // logic
    int cur = 0;
    for(const auto &t : T) {
        cur = max(cur, t);
        cur += A;
        cout << cur << endl;
    }

    // output

    return 0;
}
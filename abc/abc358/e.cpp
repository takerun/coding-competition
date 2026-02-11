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
#include <atcoder/modint>
using mint = atcoder::modint998244353;

int main() {
    fastIO();
    // input
    int K;
    cin >> K;
    vector<int> C(26, 0);
    for(auto &c : C) cin >> c;
    K = min(K, accumulate(begin(C), end(C), 0));

    // logic
    for(int i = 1; i <= K; i++) {
        vector<int> c = C;
        sort(begin(c), end(c));
        int64 l = 0, r = 26;
        while((l + 1) < r) {
            int64 mid = (l + r) / 2;
            if(C[mid] < 1)
                l = mid;
            else
                r = mid;
        }
        cout << 25 - l << endl;
    }

    // output
    // cout << ans.val() - 1 << endl;
    return 0;
}
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
    int64 N, Q;
    cin >> N >> Q;
    vector<int64> A(N, 0);
    for(auto &a : A) cin >> a;
    sort(begin(A), end(A));

    // logic
    int64 b, k;
    for(int q = 0; q < Q; q++) {
        cin >> b >> k;
        auto f = [&](int64 x) {
            int64 ub = upper_bound(begin(A), end(A), b + x) - begin(A);
            int64 lb = lower_bound(begin(A), end(A), b - x) - begin(A);
            return ub - lb >= k;
        };
        int64 ng = -1, ok = 2e18;  // ng:解が存在しない値, ok:解が存在する値
        while(abs(ok - ng) > 1) {
            int64 mid = (ok + ng) / 2;
            if(f(mid))
                ok = mid;
            else
                ng = mid;
        }
        cout << ok << endl;
    }

    // output

    return 0;
}
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
    int64 N, M;
    cin >> N >> M;
    vector<int64> A(N, 0);
    for(auto &a : A) cin >> a;

    // logic
    auto f = [&](int64 x) {
        int64 sum = 0;
        for(int i = 0; i < N; i++) {
            sum += min(x, A[i]);
        }
        return sum <= M;
    };
    int64 ng = M + 2, ok = 0;  // 反転も可能
    while(abs(ok - ng) > 1) {
        int64 mid = (ok + ng) / 2;
        if(f(mid))
            ok = mid;
        else
            ng = mid;
    }

    // output
    if(ok > M) {
        cout << "infinite" << endl;
    } else {
        cout << ok << endl;
    }
    return 0;
}
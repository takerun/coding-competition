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
    int N, L, K;
    cin >> N >> L >> K;
    vector<int> A(N, 0);
    for(auto &a : A) cin >> a;

    // logic
    auto f = [&](int mn) {
        int pcur = 0, pprev = 0, pnum = 0;
        for(int i = 0; i < N; i++) {
            pcur = A[i];
            if(pcur - pprev >= mn) {
                pprev = pcur;
                pnum++;
            }
        }
        if(L - pprev >= mn) pnum++;
        return pnum >= K + 1;
    };
    int ng = 1e9, ok = 0;
    while(abs(ok - ng) > 1) {
        int64 mid = (ok + ng) / 2;
        if(f(mid))
            ok = mid;
        else
            ng = mid;
    }

    // output
    cout << ok << endl;
    return 0;
}
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
// https://atcoder.github.io/ac-library/production/document_en/dsu.html

int main() {
    fastIO();
    // input
    int64 N, M;
    cin >> N >> M;
    vector<int64> A(N, 0LL), AM(N, 0LL);
    for(auto &a : A) {
        cin >> a;
    }

    // logic
    map<int64, int> cntr;
    int64 cur = 0LL;
    for(int i = 0; i < N - 1; i++) {
        AM[i] = cur;
        cntr[cur]++;
        cur += A[i];
        cur %= M;
    }
    AM[N - 1] = cur;
    cntr[cur]++;

    // output
    int64 ans = 0LL;
    for(int i = 0; i < N; i++) {
        ans += cntr[AM[i]] - 1;
        cntr[AM[i]]--;
        cur += A[(i + N - 1) % N];
        cur %= M;
        cntr[cur]++;
    }
    cout << ans << endl;
    return 0;
}
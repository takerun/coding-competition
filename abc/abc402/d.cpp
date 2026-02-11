#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int64 N, M;
    cin >> N >> M;

    // logic
    vector<int64> group(N, 0LL);
    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b, a--, b--;
        group[(a + b) % N]++;
    }

    // output
    int64 sm = accumulate(begin(group), end(group), 0);
    int64 ans = 0LL;
    for(int i = 0; i < N; i++) {
        ans += group[i] * (sm - group[i]);
    }
    cout << ans / 2 << endl;
    return 0;
}
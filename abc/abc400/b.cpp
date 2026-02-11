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
    int64 ans = 1LL, elem = 1LL;
    for(int i = 0; i < M; i++) {
        elem *= N;
        ans += elem;
        if(ans > 1e9) {
            cout << "inf" << endl;
            return 0;
        }
    }

    // output
    cout << ans << endl;
    return 0;
}
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
    int64 N, L, R;
    cin >> N >> L >> R;

    // logic
    vector<int64> pow2(20);
    pow2[0] = 1;
    for(int i = 1; i < 20; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }
    vector<vector<int64>> ans;
    while(L != R + 1) {
        int64 i = 0;
        while(L % pow2[i + 1] == 0 and L + pow2[i + 1] <= R + 1) {
            i++;
        }
        // ans.push_back({L, L + pow2[i]});
        ans.push_back({i, L / pow2[i]});
        L += pow2[i];
    }

    // output
    int64 rem = 0, rbuf;
    for(const auto &a : ans) {
        cout << "? " << a[0] << " " << a[1] << endl << flush;
        cin >> rbuf;
        if(rbuf == -1) return 0;
        rem += rbuf;
    }
    cout << "! " << rem % 100 << endl;
    return 0;
}
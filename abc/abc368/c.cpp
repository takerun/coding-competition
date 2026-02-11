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
    int64 N;
    cin >> N;
    vector<int64> H(N, 0LL);
    for(auto &a : H) cin >> a;

    // logic
    vector<int> state = {0, 4, 3};
    int rem = 0;
    int64 ans = 0LL, si = 0LL, hi = 0LL, h = H[hi++];
    while(h > 0) {
        if(h - state[si] > 0) {
            h -= state[si];
            if(si == 1) ans += 2;
            if(si == 2) ans += 1;
            si = 0;
            ans += (h / 5) * 3;
            rem = h % 5;
            if(rem == 1) {
                ans += 1;
                si = 1;
            } else if(rem == 2) {
                ans += 2;
                si = 2;
            } else if(rem == 3 or rem == 4) {
                ans += 3;
                si = 0;
            }
            h = 0;
        } else {
            if(si == 1) {
                if(h == 1) {
                    h = 0;
                    ans += 1;
                    si = 2;
                } else {
                    h = 0;
                    ans += 2;
                    si = 0;
                }

            } else if(si == 2) {
                h = 0;
                ans += 1;
                si = 0;
            }
        }
        // cout << h << " " << si << " " << ans << endl;
        if(hi < N and h <= 0) h = H[hi++];
    }

    // output
    cout << ans << endl;
    return 0;
}
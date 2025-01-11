#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;
int64 pw(int64 a, int64 n) { return n == 0 ? 1LL : pw(a, n - 1) * a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int64 L, R;
    cin >> L >> R;

    // logic
    auto func = [&](int64 x) {
        string X = to_string(x);
        int64 h = int(X[0] - '0'), n = X.size();
        if(n == 1) return 0LL;

        int64 res = 0;
        // <= n - 2
        for(int d = 1; d <= n - 2; d++) {
            for(int t = 1; t <= 9; t++) {
                res += pw(t, d);
            }
        }
        // n - 1, smaller
        int64 d = n - 1;
        for(int t = 1; t < h; t++) {
            res += pw(t, d);
        }
        // n - 1, just
        for(int i = 1; i <= n - 1; i++) {
            int64 Xi = int(X[i] - '0'), T = min(h, Xi);
            for(int t = 0; t < T; t++) {
                res += pw(h, n - 1 - i);
            }
            if(T == h) break;
        }
        // just
        bool is = true;
        for(int d = 1; d <= n - 1; d++) {
            is &= (int(X[d] - '0') < h);
        }
        if(is) res++;
        return res;
    };

    // output
    cout << func(R) - func(L - 1) << endl;
    return 0;
}
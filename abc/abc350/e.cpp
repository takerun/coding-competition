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
    int64 N, A, X, Y;
    cin >> N >> A >> X >> Y;

    // logic
    map<int64, double> m;
    auto dfs = [&](auto &&self, const int64 n) -> double {
        // exit conditions
        if(n == 0) return 0;

        // shortcut conditions

        // use memo
        if(m.count(n)) return m[n];

        // try all moves
        double res = DBL_MAX;
        res = min(res, self(self, n / A) + X);

        double dice = 0;
        dice += self(self, n / 2) + self(self, n / 3) + self(self, n / 4) +
                self(self, n / 5) + self(self, n / 6);
        res = min(res, (dice + Y * 6) / 5);
        return m[n] = res;
    };

    // output
    cout << fixed << setprecision(15);
    cout << dfs(dfs, N) << endl;
    return 0;
}
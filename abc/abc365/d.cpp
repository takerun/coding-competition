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
    int N;
    cin >> N;
    string S;
    cin >> S;

    // logic
    map<char, int> jmap = {{'R', 0}, {'P', 1}, {'S', 2}};
    map<vector<int>, int> m;
    auto dfs = [&](auto &&self, const int r, const int prev_move) -> int {
        // exit conditions
        if(r == N) return 0;

        // shortcut conditions

        // use memo
        if(m.count({r, prev_move})) return m[{r, prev_move}];

        // try all moves
        int res = 0;
        for(int i = 0; i < 3; i++) {
            if(i == ((jmap[S[r]] - 1) % 3 + 3) % 3) continue;
            if(i == prev_move) continue;

            if(i == jmap[S[r]]) {
                res = max(res, self(self, r + 1, i));
            } else {
                res = max(res, self(self, r + 1, i) + 1);
            }
        }
        return m[{r, prev_move}] = res;
    };

    // output
    cout << dfs(dfs, 0, -1) << endl;
    // for(const auto &[key, val] : m) {
    //     cout << key[0] << " " << key[1] << " " << val << endl;
    // }
    return 0;
}
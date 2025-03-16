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
    int N, K;
    cin >> N >> K;
    vector<int> R(N, 0);
    for(auto &a : R) cin >> a;

    // logic
    vector<int> r(N, 0);
    auto dfs = [&](auto &&self, int n) -> void {
        // exit conditions
        if(n == N) {
            if(accumulate(begin(r), end(r), 0) % K == 0) {
                for(const auto &a : r) cout << a << " ";
                cout << endl;
            }
            return;
        }

        // try all moves
        for(int v = 1; v <= R[n]; v++) {
            r[n] = v;
            self(self, n + 1);
            // 戻すかも
        }
    };
    dfs(dfs, 0);

    // output
    return 0;
}
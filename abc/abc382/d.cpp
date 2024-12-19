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
    int N, M;
    cin >> N >> M;

    // logic
    vector<vector<int>> Ans;
    vector<int> Base(N, 0);
    auto dfs = [&](auto &&self, const int i, const int rest) -> void {
        // exit conditions
        if(i == N) {
            Ans.push_back(Base);
            return;
        }

        // try all moves
        for(int v = 0; v <= rest; v++) {
            Base[i] = v;
            self(self, i + 1, rest - v);
        }
    };

    // output
    dfs(dfs, 0, M - 10 * (N - 1) - 1);
    cout << Ans.size() << endl;
    for(int i = 0; i < Ans.size(); i++) {
        int d = 1;
        for(int j = 0; j < N; j++) {
            cout << d + Ans[i][j] << " \n"[j == N - 1];
            d = d + Ans[i][j] + 10;
        }
    }
    return 0;
}
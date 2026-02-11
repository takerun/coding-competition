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
    vector<string> S(N);
    for(auto &s : S) cin >> s;

    // logic
    vector<int> ans;
    vector<bool> x(M, false);
    int num = 0;
    auto dfs = [&](auto &&self, const int idx) -> void {
        // exit conditions
        if(idx == N) {
            bool ok = true;
            for(int i = 0; i < M; i++) {
                ok = ok and x[i];
            }
            if(ok) ans.push_back(num);
            return;
        }

        // try all moves
        vector<int> buf;
        for(int i = 0; i < M; i++) {
            if(!x[i] and S[idx][i] == 'o') {
                x[i] = true;
                buf.push_back(i);
            }
        }
        num++;
        self(self, idx + 1);
        for(const auto &b : buf) {
            x[b] = false;
        }
        num--;
        self(self, idx + 1);
    };
    dfs(dfs, 0);

    // output
    cout << *min_element(begin(ans), end(ans)) << endl;
    return 0;
}
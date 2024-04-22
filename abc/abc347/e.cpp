// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
typedef long long int int64;

int main() {
    fastIO();
    // input
    int64 N, Q;
    cin >> N >> Q;

    // logic
    set<int64> S;
    vector<int64> cuml(Q + 1, 0);
    vector<vector<int>> se(N, vector<int>());
    for(int i = 0; i < Q; i++) {
        int64 x;
        cin >> x;
        x--;
        if(S.count(x) == 0) {
            S.insert(x);
            se[x].push_back(i);
        } else {
            S.erase(x);
            se[x].push_back(i);
        }

        cuml[i + 1] = cuml[i] + S.size();
    }

    // output
    for(int i = 0; i < N; i++) {
        int64 sum = 0;
        if(se[i].size() % 2 == 1) se[i].push_back(Q);
        for(int j = 0; j < se[i].size() / 2; j++) {
            sum += cuml[se[i][j * 2 + 1]] - cuml[se[i][j * 2]];
        }
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
typedef long long int int64;

map<int64, int64> m;
int64 dfs(int64 x) {
    // exit conditions
    if(x == 1) return 0;

    // shotcut conditions

    // use memo
    if(m.count(x)) return m[x];

    // try all moves
    return m[x] = dfs(x / 2) + dfs((x + 1) / 2) + x;
}

int main() {
    fastIO();
    // input
    int64 N;
    cin >> N;

    // logic

    // output
    cout << dfs(N);
    cout << endl;
    return 0;
}
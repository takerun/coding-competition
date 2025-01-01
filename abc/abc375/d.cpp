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
    string S;
    cin >> S;

    // logic
    map<int, vector<int64>> m;
    for(int c = 'A'; c <= 'Z'; c++) {
        m[c].push_back(0LL);
        for(int j = 0; j <= S.size(); j++) {
            m[c][j + 1] = m[c][j];
            if(S[j] == c) m[c][j + 1]++;
        }
    }
    int64 ans = 0;
    for(int c = 'A'; c <= 'Z'; c++) {
        for(int j = 1; j <= S.size() - 2; j++) {
            ans += (m[c][j] - m[c][0]) * (m[c][S.size()] - m[c][j + 1]);
        }
    }

    // output
    cout << ans << endl;
    return 0;
}
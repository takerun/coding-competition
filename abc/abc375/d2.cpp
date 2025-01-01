#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    string S;
    cin >> S;

    // logic
    map<char, set<int64>> posSet;
    for(int64 i = 0LL; i < S.size(); i++) {
        posSet[S[i]].insert(i);
    }
    int64 ans = 0LL;
    for(const auto &[c, st] : posSet) {
        if(st.size() <= 1) continue;
        int64 cuml = 0LL, cnt = 0LL;
        for(const auto &s : st) {
            ans += (s - 1) * cnt - cuml;
            cuml += s;
            cnt++;
        }
    }

    // output
    cout << ans << endl;
    return 0;
}
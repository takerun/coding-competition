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
    string S;
    cin >> S;

    // logic
    set<string> ss;
    for(int i = 0; i < S.size(); i++) {
        for(int j = 1; j <= S.size() - i; j++) {
            ss.insert(S.substr(i, j));
        }
    }

    // output
    cout << ss.size();
    cout << endl;
    return 0;
}
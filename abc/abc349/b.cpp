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
    map<int, int> cntr;
    for(int i = 0; i < S.size(); i++) {
        cntr[S[i]]++;
    }
    map<int, int> mp;
    for(const auto &[key, val] : cntr) {
        mp[val]++;
    }

    for(int i = 1; i <= 100; i++) {
        if(mp[i] != 0 && mp[i] != 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    // output
    cout << "Yes";
    cout << endl;
    return 0;
}
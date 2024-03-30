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
    map<char, int> mp;
    for(int i = 0; i < S.size(); i++) {
        mp[S[i]] += 1;
    }

    for(const auto &[key, val] : mp) {
        if(val == 1) {
            cout << S.find(key) + 1;
        }
    }
    // output
    cout << endl;
    return 0;
}
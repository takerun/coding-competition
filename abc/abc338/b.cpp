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
        mp[S[i]]++;
    }

    // output
    auto pr =
        *max_element(begin(mp), end(mp), [](const auto &x, const auto &y) {
            return x.second < y.second ||
                   (x.second == y.second && x.first > y.first);
        });
    cout << pr.first;
    cout << endl;
    return 0;
}
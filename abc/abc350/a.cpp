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
    int num = stoi(S.substr(3));
    // int num = int(S[3] - '0') * 100 + int(S[4] - '0') * 10 + int(S[5] - '0');

    // output
    if(num <= 349 && num >= 1 && num != 316) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}
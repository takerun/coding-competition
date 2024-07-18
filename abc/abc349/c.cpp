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
    string S, T;
    cin >> S >> T;

    // logic
    for(int i = 0; i < 3; i++) {
        T[i] = tolower(T[i]);
    }
    if(T[2] == 'x') T = T.substr(0, 2);

    int checkCounter = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == T[checkCounter]) checkCounter++;
        if(checkCounter == T.size()) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    // output
    cout << "No";
    cout << endl;
    return 0;
}
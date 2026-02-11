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
    int si = 0;
    for(int i = 0; i < T.size(); i++) {
        if(S[si] == T[i]) {
            cout << i + 1 << " ";
            si++;
        }
    }

    // output
    cout << endl;
    return 0;
}
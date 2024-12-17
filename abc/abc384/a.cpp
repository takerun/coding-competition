// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int int64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int N;
    cin >> N;
    char c1, c2;
    cin >> c1 >> c2;
    string S;
    cin >> S;

    // logic
    for(int i = 0; i < S.size(); i++) {
        if(S[i] != c1) {
            cout << c2;
        } else {
            cout << c1;
        }
    }
    cout << endl;
    // output

    return 0;
}
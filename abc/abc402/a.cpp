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
    for(int i = 0; i < S.size(); i++) {
        if(S[i] <= 'Z' and S[i] >= 'A') {
            cout << S[i];
        }
    }

    // output
    cout << endl;
    return 0;
}
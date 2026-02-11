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
    for(int i = S.size() - 1; i >= 1; i--) {
        if(S[i] == 'A' and S[i - 1] == 'W') {
            S[i] = 'C';
            S[i - 1] = 'A';
        }
    }

    // output
    cout << S << endl;
    return 0;
}
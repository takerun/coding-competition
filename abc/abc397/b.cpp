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
    int Si = 0;
    int cnt = 0;
    while(Si < S.size()) {
        if(S[Si] == 'i' and (cnt % 2 == 0)) {
            Si++;
        } else if(S[Si] == 'o' and (cnt % 2 == 1)) {
            Si++;
        }

        cnt++;
    }

    if(cnt % 2 == 1) cnt++;

    // output
    cout << cnt - S.size() << endl;
    return 0;
}
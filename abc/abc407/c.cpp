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
    int64 ans = 0LL, cum = 0LL;
    for(int i = S.size() - 1; i >= 0; i--) {
        int64 si = int64(S[i] - '0');
        if(si >= cum) {
            si -= cum;
        } else {
            si += 10 - cum;
        }
        cum += si;
        cum %= 10;
        ans += si;
        ans++;
    }

    // output
    cout << ans << endl;
    return 0;
}
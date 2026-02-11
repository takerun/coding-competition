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
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < S.size(); i++) cin >> S[i];

    // logic
    bool is_logout = true;
    int err = 0;
    for(int i = 0; i < N; i++) {
        if(is_logout and S[i] == "private") err++;
        if(S[i] == "login") is_logout &= false;
        if(S[i] == "logout") is_logout |= true;
    }

    // output
    cout << err << endl;
    return 0;
}
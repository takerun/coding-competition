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
    map<char, int> s;
    for(int i = 0; i < S.size(); i++) {
        s[S[i]]++;
    }

    // output
    for(char c = 'a'; c <= 'z'; c++) {
        if(s[c] == 0) {
            cout << c << endl;
            break;
        }
    }

    return 0;
}
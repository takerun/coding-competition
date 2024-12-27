// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
void Yes(bool a) { cout << (a ? "Yes" : "No") << endl; }
typedef long long int int64;

int main() {
    fastIO();
    // input
    string S;
    cin >> S;

    // logic
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == 'A') a++;
        if(S[i] == 'B') b++;
        if(S[i] == 'C') c++;
    }

    // output
    Yes(a == 1 and b == 1 and c == 1);
    return 0;
}
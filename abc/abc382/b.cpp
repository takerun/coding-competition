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
    int N, D;
    cin >> N >> D;
    string S;
    cin >> S;

    // logic
    int c = D;
    for(int i = N - 1; i >= 0; i--) {
        if(S[i] == '@') c--, S[i] = '.';
        if(c == 0) break;
    }

    // output
    cout << S << endl;
    return 0;
}
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
    int N;
    cin >> N;
    string S;
    cin >> S;

    // logic
    int ans = 0;
    for(int i = 0; i < N - 2; i++) {
        if(S[i] == '#' and S[i + 1] == '.' and S[i + 2] == '#') ans++;
    }

    // output
    cout << ans << endl;
    return 0;
}
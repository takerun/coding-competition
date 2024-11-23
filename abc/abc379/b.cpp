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
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // logic
    int k = 0, ans = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'X') {
            k = 0;
            continue;
        }
        if(++k == K) {
            ans++;
            k = 0;
        }
    }

    // output
    cout << ans << endl;
    return 0;
}
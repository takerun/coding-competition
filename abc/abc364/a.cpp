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
    vector<string> S(N);
    for(auto &a : S) cin >> a;

    // logic
    string prev, cur;
    prev = S[0];
    for(int i = 1; i < N; i++) {
        cur = S[i];
        if(prev == "sweet" and cur == "sweet" and i < N - 1) {
            Yes(false);
            return 0;
        }
        prev = cur;
    }

    // output
    Yes(true);
    return 0;
}
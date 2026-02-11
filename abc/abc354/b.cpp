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
    int64 sumc = 0, c = 0;
    for(int i = 0; i < N; i++) {
        cin >> S[i] >> c;
        sumc += c;
    }

    // logic
    sort(begin(S), end(S));

    // output
    cout << S[sumc % N] << endl;

    return 0;
}

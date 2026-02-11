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
    int64 N, T;
    cin >> N >> T;

    // logic
    vector<int64> BingoH(N, 0LL), BingoW(N, 0LL);
    int64 slash = 0LL, Bslash = 0LL;
    for(int i = 0; i < T; i++) {
        int64 a;
        cin >> a;
        --a;
        int64 r = a % N, q = a / N;
        Bslash += (r == q);
        slash += (r + q == N - 1);
        if(++BingoH[r] == N or ++BingoW[q] == N or Bslash == N or slash == N) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    // output
    cout << -1 << endl;
    return 0;
}
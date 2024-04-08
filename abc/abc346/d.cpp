// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
typedef long long int int64;

int main() {
    fastIO();
    // input
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int64> C(N, 0);
    for(int64 &c : C) cin >> c;

    // logic
    vector<int64> evenCuml(N + 1, 0), oddCuml(N + 1, 0);
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            if(S[i] == '0') {
                oddCuml[i + 1] = oddCuml[i] + C[i];
                evenCuml[i + 1] = evenCuml[i];
            } else {
                oddCuml[i + 1] = oddCuml[i];
                evenCuml[i + 1] = evenCuml[i] + C[i];
            }
        } else {
            if(S[i] == '0') {
                oddCuml[i + 1] = oddCuml[i];
                evenCuml[i + 1] = evenCuml[i] + C[i];
            } else {
                oddCuml[i + 1] = oddCuml[i] + C[i];
                evenCuml[i + 1] = evenCuml[i];
            }
        }
    }

    int64 mn = 1e18;
    for(int i = 1; i <= N - 1; i++) {
        mn = min(mn, oddCuml[i] - oddCuml[0] + evenCuml[N] - evenCuml[i]);
        mn = min(mn, evenCuml[i] - evenCuml[0] + oddCuml[N] - oddCuml[i]);
    }

    // output
    cout << mn;
    cout << endl;
    return 0;
}
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
    vector<float> X(N, 0), Y(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    // logic

    for(int i = 0; i < N; i++) {
        int mx = INT_MIN;
        int ansi = 0;
        for(int j = 0; j < N; j++) {
            if(mx < pow(X[i] - X[j], 2) + pow(Y[i] - Y[j], 2)) {
                mx = pow(X[i] - X[j], 2) + pow(Y[i] - Y[j], 2);
                ansi = j;
            }
        }
        cout << ansi + 1 << endl;
    }

    // output
    cout << endl;
    return 0;
}
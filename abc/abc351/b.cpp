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
    vector<string> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // logic
    for(int i = 0; i < N; i++) {
        string b;
        cin >> b;
        for(int j = 0; j < N; j++) {
            if(b[j] != A[i][j]) {
                cout << i + 1 << " " << j + 1;
            }
        }
    }

    // output
    cout << endl;
    return 0;
}
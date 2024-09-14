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
    vector<int> A(N, 0);
    vector<char> S(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> S[i];
        A[i]--;
    }

    // logic
    int mn = INT_MAX;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            int l = i, r = j, t = 0;
            for(int k = 0; k < N; k++) {
                if(S[k] == 'L') {
                    t += abs(A[k] - l);
                    l = A[k];
                } else {
                    t += abs(A[k] - r);
                    r = A[k];
                }
            }
            mn = min(mn, t);
        }
    }

    // output
    cout << mn << endl;
    return 0;
}
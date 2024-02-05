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
    vector<int64> Q(N, 0);
    for(int64 &q : Q) cin >> q;
    vector<int64> A(N, 0);
    for(int64 &a : A) cin >> a;
    vector<int64> B(N, 0);
    for(int64 &b : B) cin >> b;

    // logic
    int64 mx = 0;
    for(int i = 0; i <= 1e6; i++) {
        int64 mn = 1e15;
        for(int j = 0; j < N; j++) {
            int64 rem = Q[j] - A[j] * i;
            if(rem < 0) {
                mn = -1e15;
            } else if(B[j] > 0) {
                mn = min(mn, rem / B[j]);
            }
        }
        mx = max(mx, mn + i);
    }

    // output
    cout << mx;
    cout << endl;
    return 0;
}
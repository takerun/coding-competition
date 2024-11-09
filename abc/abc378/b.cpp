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
    vector<pair<int, int>> qr(N);
    int q, r;
    for(int i = 0; i < N; i++) {
        cin >> q >> r;
        qr[i] = {q, r};
    }

    // logic
    int Q, t, d;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        cin >> t >> d;
        t--;
        auto [q, r] = qr[t];
        int oo = d / q, rr = d % q;
        if(rr <= r) {
            rr = r;
        } else {
            rr = q + r;
        }

        cout << oo * q + rr << endl;
    }

    // output

    return 0;
}
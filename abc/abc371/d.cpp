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
    vector<int64> X(N);
    for(auto &a : X) cin >> a;
    vector<int64> cuml(N + 1, 0LL);
    for(int i = 0; i < N; i++) {
        int64 a;
        cin >> a;
        cuml[i + 1] = cuml[i] + a;
    }
    // usage:
    // cuml[right] - cuml[left]; // sum [left, right)
    int Q;
    cin >> Q;

    // logic
    for(int i = 0; i < Q; i++) {
        int64 l, r;
        cin >> l >> r;
        cout << cuml[upper_bound(begin(X), end(X), r) - begin(X)] -
                    cuml[lower_bound(begin(X), end(X), l) - begin(X)]
             << endl;
    }

    // output

    return 0;
}
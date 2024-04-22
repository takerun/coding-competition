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
    int64 N, A, B;
    cin >> N >> A >> B;
    vector<int64> D(N, 0);
    for(int64 &d : D) {
        cin >> d;
        d %= A + B;
    }
    sort(begin(D), end(D));
    D.erase(unique(begin(D), end(D)), end(D));

    // logic
    bool ans = false;
    for(int i = 0; i < N - 1; i++) {
        ans |= D[i + 1] - D[i] > B;
    }
    ans |= D[0] + A + B - D[N - 1] > B;

    // output
    cout << (ans ? "Yes" : "No");
    cout << endl;
    return 0;
}
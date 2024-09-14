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
template <class T>
inline bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    fastIO();
    // input
    int N;
    cin >> N;
    vector<int64> A(N, 0LL);
    for(auto& a : A) cin >> a;

    // logic
    // initialize dp
    vector<int64> even(N + 1, 0LL), odd(N + 1, 0LL);

    // init sub score
    even[0] = 0LL;
    odd[0] = LONG_MIN;

    // update dp
    for(int i = 1; i <= N; i++) {
        even[i] = max(even[i - 1], odd[i - 1] + 2 * A[i - 1]);
        odd[i] = max(odd[i - 1], even[i - 1] + A[i - 1]);
    }

    // output
    cout << max(even[N], odd[N]) << endl;
    return 0;
}
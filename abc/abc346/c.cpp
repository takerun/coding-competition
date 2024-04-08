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
    int64 K;
    cin >> N >> K;

    // logic
    set<int64> buf;
    int64 sum = (1 + K) * K / 2;
    for(int i = 0; i < N; i++) {
        int64 A;
        cin >> A;
        if(buf.count(A) == 1 || (A > K)) continue;
        sum -= A;
        buf.insert(A);
    }

    // output
    cout << sum;
    cout << endl;
    return 0;
}
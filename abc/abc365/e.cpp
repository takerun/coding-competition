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
    int64 N;
    cin >> N;
    vector<int64> A(N, 0LL);
    for(auto &a : A) cin >> a;

    // logic
    int64 ans = 0;
    for(int i = 0; i < 28; i++) {
        int64 digit = 1LL << i;
        int x = 0;
        int64 count0 = 1LL, count1 = 0LL;
        for(int j = 0; j < N; j++) {
            x = x ^ (A[j] & digit);
            if(x == 0)
                count0++;
            else
                count1++;
        }
        ans += count0 * count1 * digit;
    }

    // output
    cout << ans - accumulate(begin(A), end(A), 0LL) << endl;
    return 0;
}
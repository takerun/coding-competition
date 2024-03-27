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
    int64 N, M, K;
    cin >> N >> M >> K;

    // logic
    int64 L = lcm(N, M);
    auto f = [&](int64 x) { return x / N + x / M - 2 * (x / L); };
    int64 l = 0, r = 2e18;
    while((l + 1) < r) {
        int64 mid = (l + r) / 2;
        if(f(mid) < K)
            l = mid;
        else
            r = mid;
    }
    // output
    cout << r;
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ft(i, f, t) for (int i = f; i < (int)(t); i++)
#define all(x) std::begin(x), std::end(x)
typedef long long int int64;

int main()
{
    fastIO();
    // input
    int64 N, S, K, p, q, sum;
    sum = 0;
    cin >> N >> S >> K;
    rep(i, N)
    {
        cin >> p >> q;
        sum += p * q;
    }

    // logic
    if (sum < S)
    {
        sum += K;
    }

    // output
    cout << sum;
    cout << endl;
    return 0;
}
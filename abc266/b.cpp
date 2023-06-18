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

    // logic
    int64 N;
    cin >> N;

    int64 r = N % 998244353;

    if (r >= 0)
    {
        cout << r;
    }
    else
    {
        cout << r + 998244353;
    }

    cout << endl;
    return 0;
}
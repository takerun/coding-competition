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
    int M, D, y, m, d;
    fastIO();
    // input
    cin >> M >> D >> y >> m >> d;

    // logic
    d++;
    if (d > D)
    {
        d = 1;
        m++;
        if (m > M)
        {
            m = 1;
            y++;
        }
    }

    // output
    cout << y << " " << m << " " << d;
    cout << endl;
    return 0;
}
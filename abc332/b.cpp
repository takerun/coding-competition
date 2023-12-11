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
    int K, G, M, g, m;
    cin >> K >> G >> M;
    g = m = 0;

    // logic
    for (int i = 0; i < K; i++)
    {
        if (g == G)
        {
            g = 0;
        }
        else if (m == 0)
        {
            m = M;
        }
        else
        {
            if (g + m > G)
            {
                m -= G - g;
                g = G;
            }
            else
            {
                g += m;
                m = 0;
            }
        }
    }

    // output
    cout << g << " " << m;
    cout << endl;
    return 0;
}
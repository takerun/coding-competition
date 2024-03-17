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
    int N, M, m, s, T, t;
    string S;
    cin >> N >> M;
    cin >> S;
    m = M;
    T = t = 0;

    // logic
    rep(i, N)
    {
        s = S[i] - '0';
        if (s == 1)
        {
            if (m <= 0)
            {
                t++;
            }
            else
            {
                m--;
            }
        }
        else if (s == 2)
        {
            t++;
        }
        else
        {
            m = M;
            t = 0;
        }

        if (t > T)
        {
            T = t;
        }
    }

    // output
    cout << T;
    cout << endl;
    return 0;
}
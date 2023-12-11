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
    string S;
    char a, b, c;
    double out = 0;
    cin >> S;

    // logic

    for (int i = 1; i <= S.length() - 2; i++)
    {
        a = S[i - 1];
        b = S[i];
        c = S[i + 1];
        if ((a == 'A' || a == '?') && (b == 'B' || b == '?') && (c == 'C' || c == '?'))
        {
            int qnum = 1;
            if (a == '?')
            {
                qnum = qnum * 3;
            }
            if (b == '?')
            {
                qnum = qnum * 3;
            }
            if (c == '?')
            {
                qnum = qnum * 3;
            }
            out = out + double(1) / double(qnum);
        }
    }

    cout << std::setprecision(15) << out;
    cout << endl;
    return 0;
}
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
    int N, a, cnt;
    cnt = 0;
    cin >> N;
    // vector<int> A(N);
    rep(i, N)
    {
        cin >> a;
        if (a == 0)
        {
            cout << 0 << endl;
            return 0;
        }

        if (a < 0)
        {
            cnt++;
        }
    }

    // logic
    if (cnt % 2 == 0)
    {
        cout << "+";
    }
    else
    {
        cout << "-";
    }

    // output
    cout << endl;
    return 0;
}
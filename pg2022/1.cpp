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
    int N, Q;
    cin >> N >> Q;
    vector<int> L(Q), R(Q);
    rep(i, Q)
    {
        cin >> L[i] >> R[i];
    }

    vector<int> line(N, 0);
    rep(i, Q)
    {
        int l = L[i] - 1, r = R[i] - 1;
        for (int j = l; j <= r; j++)
        {
            ++line[j];
        }
    }

    int sum = 0;
    rep(i, N)
    {
        if (line[i] % 2 == 1)
        {
            ++sum;
        }
    }

    cout << sum << endl;
    return 0;
}
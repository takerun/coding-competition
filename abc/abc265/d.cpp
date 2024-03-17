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

    // your code
    int64 N, P, Q, R;
    cin >> N >> P >> Q >> R;
    vector<int64> x(N), cuml(N + 1);
    cuml[0] = 0;
    rep(i, N)
    {
        cin >> x[i];
        cuml[i + 1] = cuml[i] + x[i];
    }

    rep(i, N + 1)
    {
        if (binary_search(all(cuml), cuml[i] + P) &&
            binary_search(all(cuml), cuml[i] + P + Q) &&
            binary_search(all(cuml), cuml[i] + P + Q + R))
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
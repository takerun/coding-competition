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
    int N;
    cin >> N;
    vector<int64> A(N * 3);
    vector<int> idx(N * 3);
    rep(i, N * 3)
    {
        cin >> A[i];
        idx[i] = i;
    }

    // インデックスソート
    sort(idx.begin(), idx.end(), [&A](int l, int r)
         { return A[l] < A[r]; });

    vector<int> rtn(N);
    for (int i = N; i < N * 2; i++)
    {
        rtn[i - N] = idx[i] + 1;
    }

    sort(all(rtn));
    rep(i, N)
    {
        cout << rtn[i] << endl;
    }

    return 0;
}
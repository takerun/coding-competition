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

#include <atcoder/modint>
using mint = atcoder::modint998244353;

// 解けてません
int main()
{
    fastIO();

    // logic
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N)
    {
        cin >> a[i];
    }
    vector<int> A(N - 1), B(N - 1);
    rep(i, N - 1)
    {
    }

    cout << endl;
    return 0;
}
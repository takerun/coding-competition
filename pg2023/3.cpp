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

int permutationMethod(int n, int r)
{
    r = n - r;
    int sum = 1;
    int i;
    for (i = n; i >= r + 1; i--)
        sum *= i;
    return sum;
}

int main()
{
    fastIO();
    // input
    int N, K;
    cin >> N >> K;
    vector<int64> A(N);

    rep(i, N)
    {
        cin >> A[i];
    }
    mint sum = 0;
    mint ssum = 0;

    // logic
    for (int i = 0; i < K; i++)
    {
        map<int64, int> dct;
        int cnt = 0;
        for (int j = i; j < N; j = j + K)
        {
            cnt++;
            map<int64, int>::iterator itr = dct.find(A[j]);
            if (itr != dct.end())
            {
                dct[A[j]] = dct[A[j]] + 1;
            }
            else
            {
                dct[A[j]] = 1;
            }
        }

        ssum = permutationMethod(cnt, 0);
        auto iter = dct.begin();
        while (iter != dct.end())
        {
            ssum = ssum / permutationMethod(iter->second, 0);
            ++iter;
        }

        sum = sum + ssum;
    }

    // output
    cout << sum.val();
    cout << endl;
    return 0;
}
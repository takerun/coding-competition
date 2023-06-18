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
    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    stack<int> s;
    for (int i = N - 1; i >= 0; i--)
    {
        int a = A[i];
        if (a == 1)
        {
            // 削除作業
            int j = 2;
            while (!s.empty() && s.top() == j)
            {
                s.pop();
                j++;
            }
        }
        else
        {
            s.push(a);
        }
    }

    int64 sum = 0;
    while (!s.empty())
    {
        sum = sum + s.top();
        s.pop();
    }
    cout << sum << endl;
    return 0;
}
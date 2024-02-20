#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
typedef long long int int64;

int main()
{
    fastIO();
    // input
    int64 N, q, i, ans;
    cin >> N;

    // logic
    N--;
    i = 1;
    ans = 0;
    while (N != 0)
    {
        q = N / 5;
        ans += (N % 5) * 2 * i;
        N = q;
        i *= 10;
    }

    // output
    cout << ans;
    cout << endl;
    return 0;
}
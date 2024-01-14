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
    int64 A, M, L, R, ans;
    cin >> A >> M >> L >> R;

    // logic
    L -= A;
    R -= A;

    int64 r = ((L - 1) % M + M) % M;
    int64 q = (L - 1 - r) / M;

    int64 r2 = ((R) % M + M) % M;
    int64 q2 = (R - r2) / M;

    // output
    cout << q2 - q;
    cout << endl;
    return 0;
}
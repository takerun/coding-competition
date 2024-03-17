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
    int N, Q;
    cin >> N >> Q;
    vector<int64> R(N);
    for (int i = 0; i < N; i++)
    {
        cin >> R[i];
    }
    sort(begin(R), end(R));

    // logic
    vector<int64> cuml(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        cuml[i + 1] = cuml[i] + R[i];
    }

    // output
    for (int i = 0; i < Q; i++)
    {
        int64 q;
        cin >> q;
        cout << upper_bound(begin(cuml), end(cuml), q) - begin(cuml) - 1 << endl;
    }

    cout << endl;
    return 0;
}
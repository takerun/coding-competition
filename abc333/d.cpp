#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
typedef long long int int64;
#include <atcoder/dsu>
using dsu = atcoder::dsu;

int main()
{
    fastIO();
    // input
    int N;
    cin >> N;

    dsu forest(N);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a != 1)
        {
            forest.merge(a - 1, b - 1);
        }
    }

    // logic
    auto vv = forest.groups();
    for (int i = 0; i < vv.size(); i++)
    {
        auto v = vv[i];
        for (int j = 0; j < v.size(); j++)
        {
            cout << v[j] << " ";
        }
        cout << endl;
    }

    // output
    cout << endl;
    return 0;
}
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
    // fastIO();
    // // input
    // int N;
    // cin >> N;

    // // logic
    // vector<int64> rp, ans;
    // rp.emplace_back(1);
    // for (int i = 0; i < 11; i++)
    // {
    //     rp.emplace_back(rp[i] * 10 + 1);
    // }

    // for (int i = 0; i < 12; i++)
    // {
    //     for (int j = 0; j < 12; j++)
    //     {
    //         for (int k = 0; k < 12; k++)
    //         {
    //             ans.emplace_back(rp[i] + rp[j] + rp[k]);
    //         }
    //     }
    // }

    // // output
    // sort(begin(ans), end(ans));
    // ans.erase(unique(begin(ans), end(ans)), end(ans));
    // cout << ans[N - 1];
    // cout << endl;
    // return 0;

    fastIO();

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            for (int k = 0; k < j + 1; k++)
            {
                cout << i << " " << j << " " << k << endl;
            }
        }
    }
    cout << endl;
    return 0;
}
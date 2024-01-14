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
    int N;
    cin >> N;
    // logic
    // N種類のものから重複を許して3個選ぶ
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            for (int k = 0; k < N + 1; k++)
            {
                if (i + j + k <= N)
                {
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }

    // output
    cout << endl;
    return 0;
}
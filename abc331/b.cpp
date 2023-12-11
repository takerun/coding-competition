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
    int N, S, M, L, price, item;
    fastIO();
    // input
    cin >> N >> S >> M >> L;
    vector<int> x(N, 10000000);

    // logic
    for (int i = 0; i < N / 6 + 2; i++)
    {

        for (int j = 0; j < N / 8 + 2; j++)
        {
            for (int k = 0; k < N / 12 + 2; k++)
            {
                item = 6 * i + 8 * j + 12 * k;
                price = S * i + M * j + L * k;

                for (int l = 0; l < item && l < N; l++)
                {

                    if (x[l] > price)
                    {
                        x[l] = price;
                    }
                }
            }
        }
    }

    // output
    cout << x[N - 1];
    cout << endl;
    return 0;
}
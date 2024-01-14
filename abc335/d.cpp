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
    int N, a, b, c, n;
    cin >> N;
    a = b = 0;
    c = 1;
    n = N;

    // logic
    vector<vector<int>> X(N, vector<int>(N, 0));
    while (true)
    {
        for (int i = b; i < n; i++)
        {
            X[a][i] = c++;
            b = i;
        }
        a++;
        for (int i = a; i < n; i++)
        {
            X[i][b] = c++;
            a = i;
        }
        b--;
        for (int i = b; i >= N - n; i--)
        {
            X[a][i] = c++;
            b = i;
        }
        a--;
        n--;
        for (int i = a; i >= N - n; i--)
        {
            X[i][b] = c++;
            a = i;
        }
        b++;
        if ((a == ((N + 1) / 2) - 1) && (b == ((N + 1) / 2) - 1))
        {
            break;
        }
        // if (b == (N - 1) || a == (N - 1))
        // {
        //     break;
        // }
    }

    // output
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((i == ((N + 1) / 2) - 1) && (j == ((N + 1) / 2) - 1))
            {
                cout << "T ";
            }
            else
            {
                cout << X[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
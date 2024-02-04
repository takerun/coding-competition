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
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int c = 1, x = 0, y = 0, di = 0;

    // logic
    vector<vector<int>> X(N, vector<int>(N, 0));
    X[y][x] = c;
    while (c < N * N)
    {
        int xx = x + dx[di], yy = y + dy[di];
        if (xx < N && xx >= 0 && yy < N && yy >= 0 && X[yy][xx] == 0)
        {
            x = xx;
            y = yy;
            X[y][x] = ++c;
        }
        else
        {
            di = (di + 1) % 4;
        }
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
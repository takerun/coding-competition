#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int int64;

int main()
{
    fastIO();

    int H, W;
    cin >> H >> W;
    vector<vector<char>> G(H, vector<char>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> G.at(i).at(j);
        }
    }

    // logic
    vector<vector<int64>> way(H, vector<int64>(W));
    int x, y;
    x = y = 0;
    while (1)
    {
        int xx = x, yy = y;
        if (G[xx][yy] == 'U')
        {
            x--;
        }
        else if (G[xx][yy] == 'D')
        {
            x++;
        }
        else if (G[xx][yy] == 'L')
        {
            y--;
        }
        else
        {
            y++;
        }

        if (x < 0 || x > H - 1 || y < 0 || y > W - 1)
        {
            cout << xx + 1 << ' ' << yy + 1 << endl;
            return 0;
        }

        if (way[x][y])
        {
            cout << -1 << endl;
            return 0;
        }
        way[x][y]++;
    }
}
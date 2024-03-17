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

    // logic
    deque<pair<int, int>> dq;
    for (int i = 0; i < N; i++)
    {
        dq.push_back({i + 1, 0});
    }

    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            char C;
            cin >> C;
            auto [x, y] = dq[0];
            if (C == 'R')
            {
                dq.push_front({x + 1, y});
            }
            else if (C == 'L')
            {
                dq.push_front({x - 1, y});
            }
            else if (C == 'U')
            {
                dq.push_front({x, y + 1});
            }
            else
            {
                dq.push_front({x, y - 1});
            }
        }
        else
        {
            int p;
            cin >> p;
            cout << dq[p - 1].first << " " << dq[p - 1].second << endl;
        }
    }

    cout << endl;
    return 0;
}
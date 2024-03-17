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
    int x, y, X, Y;
    X = 0;
    Y = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        X += x;
        Y += y;
    }

    // output
    if (X > Y)
    {
        cout << "Takahashi";
    }
    else if (X < Y)
    {
        cout << "Aoki ";
    }
    else
    {
        cout << "Draw";
    }

    cout << endl;
    return 0;
}
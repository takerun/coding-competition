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
    fastIO();

    // logic
    int ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

    int yarg = cx - ax, xarg = ay - cy, basis = cx * ay - ax * cy;
    if ((by * yarg + bx * xarg - basis) * (dy * yarg + dx * xarg - basis) > 0)
    {
        cout << "No" << endl;
        return 0;
    }

    yarg = dx - bx, xarg = by - dy, basis = dx * by - bx * dy;
    if ((ay * yarg + ax * xarg - basis) * (cy * yarg + cx * xarg - basis) > 0)
    {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}
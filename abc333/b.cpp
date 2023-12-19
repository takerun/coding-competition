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
    char s1, s2, t1, t2;
    int s, t;
    cin >> s1 >> s2 >> t1 >> t2;

    // logic
    s = abs(s1 - s2);
    t = abs(t1 - t2);
    if (s == 1 || s == 4)
    {
        if (t == 1 || t == 4)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
    }
    else
    {
        if (t == 1 || t == 4)
        {
            cout << "No";
        }
        else
        {
            cout << "Yes";
        }
    }

    // output
    cout << endl;
    return 0;
}
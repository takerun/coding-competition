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
    int B, G;
    cin >> B >> G;

    // logic
    if (B > G)
    {
        cout << "Bat";
    }
    else
    {
        cout << "Glove";
    }

    // output
    cout << endl;
    return 0;
}
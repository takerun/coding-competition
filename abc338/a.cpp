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
    string S;
    cin >> S;

    // logic
    if (!isupper(S[0]))
    {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 1; i < S.length(); ++i)
    {
        if (!islower(S[i]))
        {
            cout << "No" << endl;
            return 0;
        }
    }

    // output
    cout << "Yes" << endl;
    cout << endl;
    return 0;
}
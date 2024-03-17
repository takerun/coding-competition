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
    S[S.size() - 1] = '4';
    cout << S;

    // output
    cout << endl;
    return 0;
}
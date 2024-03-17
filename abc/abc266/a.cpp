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
    string astr;
    vector<int> a;
    int Asize;
    cin >> astr;
    Asize = astr.size();
    cout << astr.at(Asize / 2);

    cout << endl;
    return 0;
}
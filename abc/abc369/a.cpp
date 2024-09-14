// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
void Yes(bool a) { cout << (a ? "Yes" : "No") << endl; }
typedef long long int int64;

int main() {
    fastIO();
    // input
    int X, Y;
    cin >> X >> Y;

    // logic
    set<int> ans;
    if((X + Y) % 2 == 0) ans.insert((X + Y) / 2);
    int diff = abs(X - Y);
    if(X > Y) swap(X, Y);

    ans.insert(X - diff);
    ans.insert(Y + diff);

    // output
    cout << ans.size() << endl;

    return 0;
}
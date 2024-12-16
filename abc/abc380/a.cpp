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
    string S;
    cin >> S;

    // logic
    map<char, int> cntr;
    for(int i = 0; i < 6; i++) {
        cntr[S[i]]++;
    }

    // output
    Yes(cntr['1'] == 1 and cntr['2'] == 2 and cntr['3'] == 3);
    return 0;
}
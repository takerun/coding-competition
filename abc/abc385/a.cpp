// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int int64;
typedef unsigned long long int uint64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int A, B, C;
    cin >> A >> B >> C;
    vector<int> v = {A, B, C};

    // logic
    sort(begin(v), end(v));

    // output
    cout << ((v[2] == v[1] + v[0] or (v[0] == v[1] and v[1] == v[2])) ? "Yes"
                                                                      : "No")
         << endl;
    return 0;
}
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
typedef long long int int64;

int main() {
    fastIO();
    // input
    int N;
    cin >> N;

    // logic
    for(int i = 0; i < N; i++) {
        if(i % 3 == 2) {
            cout << "x";
        } else {
            cout << "o";
        }
    }

    // output
    cout << endl;
    return 0;
}
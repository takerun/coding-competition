// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int int64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int N, R;
    cin >> N >> R;

    // logic
    int d, a;
    for(int i = 0; i < N; i++) {
        cin >> d >> a;
        if(d == 1 and R >= 1600 and R <= 2799) {
            R += a;
        } else if(d == 2 and R >= 1200 and R <= 2399) {
            R += a;
        }
    }

    // output
    cout << R << endl;
    return 0;
}
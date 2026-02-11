#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int X, Y;
    cin >> X >> Y;

    // logic
    int ans = 0;
    for(int i = 1; i <= 6; i++) {
        for(int j = 1; j <= 6; j++) {
            if(i + j >= X or abs(i - j) >= Y) ans++;
        }
    }

    // output
    cout << fixed << setprecision(15);
    cout << double(ans) / 36 << endl;
    return 0;
}
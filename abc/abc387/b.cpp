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
    int N;
    cin >> N;

    // logic
    int ans = 2025;
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            if(N == i * j) ans -= N;
        }
    }

    // output
    cout << ans << endl;
    return 0;
}
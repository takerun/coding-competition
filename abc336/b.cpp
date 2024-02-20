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
    for(int i = 0;; i++) {
        if(N & (1 << i)) {
            cout << i << endl;
            return 0;
        }
    }
}
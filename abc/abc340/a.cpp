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
    int A, B, D;
    cin >> A >> B >> D;

    // logic
    for(int i = A; i <= B; i += D) {
        cout << i << " ";
    }

    // output
    cout << endl;
    return 0;
}
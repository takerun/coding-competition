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
    cout << "1";
    for(int i = 0; i < N; i++) {
        cout << "01";
    }

    // output
    cout << endl;
    return 0;
}
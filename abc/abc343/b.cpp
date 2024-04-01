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
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int a;
            cin >> a;
            if(a == 1) {
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }

    // logic

    // output
    cout << endl;
    return 0;
}
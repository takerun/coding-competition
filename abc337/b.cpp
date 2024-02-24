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
    string S;
    cin >> S;

    // logic
    string abc = "ABC";
    int a = 0;
    for(int i = 0; i < S.size(); i++) {
        while(a <= 2) {
            if(S[i] != abc[a]) {
                a++;
            } else {
                break;
            }
        }

        if(a > 2) {
            cout << "No";
            cout << endl;
            return 0;
        }
    }

    // output
    cout << "Yes";
    cout << endl;
    return 0;
}
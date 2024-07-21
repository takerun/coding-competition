// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
void Yes(bool a) { cout << (a ? "Yes" : "No") << endl; }
typedef long long int int64;

int main() {
    fastIO();
    // input
    int64 N;
    cin >> N;

    // logic
    if(N <= 10) {
        cout << N - 1 << endl;
        return 0;
    }
    N -= 10;
    if(N <= 9) {
        cout << N - 1 << N - 1 << endl;
        return 0;
    }
    N -= 9;
    int64 swi = 0, unit = 90;
    while(N - unit > 0) {
        N -= unit;
        if(swi % 2 == 1) {
            unit *= 10;
        }
        swi++;
    }
    int digit = to_string(unit).size();
    digit--;
    int64 base = 1;
    for(int i = 0; i < digit; i++) {
        base *= 10;
    }
    string kaibun = to_string(base + N - 1);

    // output
    if(swi % 2 == 0) {
        cout << kaibun.substr(0, kaibun.size() - 1);
        reverse(kaibun.begin(), kaibun.end());
        cout << kaibun;
    } else {
        cout << kaibun;
        reverse(kaibun.begin(), kaibun.end());
        cout << kaibun;
    }

    cout << endl;
    return 0;
}

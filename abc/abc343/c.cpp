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
    int64 N;
    cin >> N;

    // logic
    auto check = [&](int64 a) {
        string s = to_string(a);
        return s == string(rbegin(s), rend(s));
    };
    int64 ans = 1;
    for(int64 i = 2; i * i * i <= N; i++) {
        if(check(i * i * i)) ans = i * i * i;
    }

    // output
    cout << ans;
    cout << endl;
    return 0;
}
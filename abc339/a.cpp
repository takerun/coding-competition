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
    const string sep = ".";
    auto offset = string::size_type(0);
    while(1) {
        auto pos = S.find(sep, offset);
        if(pos == string::npos) {
            cout << S.substr(offset) << endl;
            break;
        }
        offset = pos + sep.size();
    }

    return 0;
}
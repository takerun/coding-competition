// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
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
    stack<int64> stk;
    int64 a;
    cin >> a;
    stk.push(a);
    for(int i = 0; i < N - 1; i++) {
        cin >> a;
        if(stk.top() != a) {
            stk.push(a);
        } else {
            while(stk.size() > 0 && stk.top() == a) {
                a++;
                stk.pop();
            }
            stk.push(a);
        }
    }

    // output
    cout << stk.size();
    cout << endl;
    return 0;
}
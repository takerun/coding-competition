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
    int Q;
    cin >> Q;

    // logic
    queue<int64> qu;
    int64 op1, op2, offset = 0LL;
    for(int i = 0; i < Q; i++) {
        cin >> op1;
        if(op1 == 1) {
            qu.push(offset);
        } else if(op1 == 2) {
            cin >> op2;
            offset += op2;
        } else {
            cin >> op2;
            int c = 0;
            while(!qu.empty() and offset - qu.front() >= op2) {
                c++;
                qu.pop();
            }
            cout << c << endl;
        }
    }

    // output
    return 0;
}
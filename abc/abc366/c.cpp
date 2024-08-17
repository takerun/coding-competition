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
    map<int, int> cntr;
    int op, offset;
    for(int i = 0; i < Q; i++) {
        cin >> op;
        if(op == 1) {
            cin >> offset;
            cntr[offset]++;
        } else if(op == 2) {
            cin >> offset;
            cntr[offset]--;
            if(cntr[offset] == 0) {
                cntr.erase(offset);
            }
        } else {
            cout << cntr.size() << endl;
        }
    }

    // output

    return 0;
}
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
    int Q;
    cin >> Q;

    // logic
    vector<int64> A, ai;
    for(int i = 0; i < Q; i++) {
        int op;
        int64 offset;
        cin >> op >> offset;
        if(op == 1) {
            A.emplace_back(offset);
        } else {
            ai.emplace_back(A.size() - offset);
        }
    }

    for(int i = 0; i < ai.size(); i++) {
        cout << A[ai[i]] << endl;
    }

    // output
    cout << endl;
    return 0;
}
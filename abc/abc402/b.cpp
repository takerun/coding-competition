#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int N;
    cin >> N;

    // logic
    int op, X;
    queue<int> Q;
    for(int i = 0; i < N; i++) {
        cin >> op;
        if(op == 1) {
            cin >> X;
            Q.push(X);
        } else {
            cout << Q.front() << endl;
            Q.pop();
        }
    }

    // output

    return 0;
}
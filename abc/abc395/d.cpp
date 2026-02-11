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
    int64 N, Q;
    cin >> N >> Q;

    // logic
    vector<int64> p(N, 0), va(N, 0), av(N, 0);
    for(int i = 0; i < N; i++) {
        p[i] = i;
        va[i] = i;
        av[i] = i;
    }
    for(int i = 0; i < Q; i++) {
        int op, a, b;
        cin >> op;
        if(op == 1) {
            cin >> a >> b, a--, b--;
            p[a] = av[b];
        } else if(op == 2) {
            cin >> a >> b, a--, b--;
            swap(va[av[a]], va[av[b]]);
            swap(av[a], av[b]);
        } else {
            cin >> a, a--;
            cout << va[p[a]] + 1 << endl;
        }
    }
    // output

    return 0;
}
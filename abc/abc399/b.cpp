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
    int N, p;
    cin >> N;
    vector<int> P(N, 0), Pv(101, 0), Pn(101, 0);
    for(int i = 0; i < N; i++) {
        cin >> P[i];
        Pv[P[i]]++;
    }

    // logic
    int r = 1;
    for(int i = 100; i >= 0; i--) {
        if(Pv[i] > 0) {
            Pn[i] = r;
            r += Pv[i];
        }
    }

    // output
    for(int i = 0; i < N; i++) {
        cout << Pn[P[i]] << endl;
    }
    return 0;
}
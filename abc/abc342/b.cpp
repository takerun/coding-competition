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
    vector<int> P(N, 0);
    for(int &p : P) cin >> p;
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        int ai = find(P.begin(), P.end(), a) - P.begin();
        int bi = find(P.begin(), P.end(), b) - P.begin();
        if(ai < bi) {
            cout << P[ai] << endl;
        } else {
            cout << P[bi] << endl;
        }
    }

    // logic

    // output
    cout << endl;
    return 0;
}
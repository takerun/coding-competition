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
typedef unsigned long long int uint64;

int main() {
    fastIO();
    // input
    string S;
    cin >> S;
    int64 Q, k, size, step, pos, flip;
    cin >> Q;
    size = S.size();

    // logic
    for(int i = 0; i < Q; i++) {
        cin >> k;
        k--;
        step = k / size;
        flip = popcount((uint64)step);
        pos = k % size;

        if(flip % 2 == 0) {
            cout << S[pos] << " ";
        } else {
            if(islower(S[pos])) {
                cout << (char)toupper(S[pos]) << " ";
            } else {
                cout << (char)tolower(S[pos]) << " ";
            }
        }
    }

    // output
    cout << endl;
    return 0;
}
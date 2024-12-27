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
    int N = 8;
    vector<string> S(N);
    for(int i = 0; i < N; i++) {
        cin >> S[i];
    }

    // logic
    set<int> H, W;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(S[i][j] == '#') {
                H.insert(i);
                W.insert(j);
            }
        }
    }

    // output
    cout << (8 - H.size()) * (8 - W.size()) << endl;
    return 0;
}
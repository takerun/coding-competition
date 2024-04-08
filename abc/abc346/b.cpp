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
    int W, B;
    cin >> W >> B;
    string S;
    for(int i = 0; i < 400; i++) {
        S += "wbwbwwbwbwbw";
    }

    // logic
    vector<int> wcuml(S.size() + 1, 0), bcuml(S.size() + 1, 0);
    for(int i = 0; i < S.size(); i++) {
        wcuml[i + 1] = wcuml[i] + (S[i] == 'w' ? 1 : 0);
        bcuml[i + 1] = bcuml[i] + (S[i] == 'b' ? 1 : 0);
    }

    // output
    int wb = W + B;
    for(int i = 0; i <= S.size() - wb; i++) {
        if(wcuml[i + wb] - wcuml[i] == W && bcuml[i + wb] - bcuml[i] == B) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
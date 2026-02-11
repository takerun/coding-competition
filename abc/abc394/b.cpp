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
    vector<string> S(N);
    vector<pair<int, int>> pos(N);  // size, index;
    for(int i = 0; i < S.size(); i++) {
        cin >> S[i];
        pos[i] = {S[i].size(), i};
    }

    // logic
    sort(begin(pos), end(pos));

    // output
    for(int i = 0; i < S.size(); i++) {
        cout << S[pos[i].second];
    }
    cout << endl;
    return 0;
}
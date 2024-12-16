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
    int N, K;
    cin >> N >> K, K--;
    string S;
    cin >> S;

    // logic
    vector<vector<char>> v2;
    vector<char> v1;
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            v1.push_back(S[i]);
            continue;
        }
        if(S[i] != v1[0]) {
            v2.push_back(v1);
            v1.clear();
        }
        v1.push_back(S[i]);
        if(i == N - 1) {
            v2.push_back(v1);
        }
    }

    if(v2[0][0] == '0') {
        swap(v2[K * 2], v2[K * 2 + 1]);
    } else {
        swap(v2[K * 2 - 1], v2[K * 2]);
    }

    // output
    for(int i = 0; i < v2.size(); i++)
        for(int j = 0; j < v2[i].size(); j++) cout << v2[i][j];
    cout << endl;
    return 0;
}
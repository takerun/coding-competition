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
    int64 N, M;
    cin >> N >> M;
    vector<int> H(M, 0), W(M, 0);
    for(int i = 0; i < M; i++) {
        cin >> H[i] >> W[i];
        H[i]--;
        W[i]--;
    }

    // logic
    set<pair<int, int>> A;
    for(int i = 0; i < M; i++) {
        A.insert({H[i], W[i]});
        if(H[i] + 2 < N and W[i] + 1 < N) A.insert({H[i] + 2, W[i] + 1});
        if(H[i] + 1 < N and W[i] + 2 < N) A.insert({H[i] + 1, W[i] + 2});
        if(H[i] - 1 >= 0 and W[i] + 2 < N) A.insert({H[i] - 1, W[i] + 2});
        if(H[i] - 2 >= 0 and W[i] + 1 < N) A.insert({H[i] - 2, W[i] + 1});
        if(H[i] - 2 >= 0 and W[i] - 1 >= 0) A.insert({H[i] - 2, W[i] - 1});
        if(H[i] - 1 >= 0 and W[i] - 2 >= 0) A.insert({H[i] - 1, W[i] - 2});
        if(H[i] + 1 < N and W[i] - 2 >= 0) A.insert({H[i] + 1, W[i] - 2});
        if(H[i] + 2 < N and W[i] - 1 >= 0) A.insert({H[i] + 2, W[i] - 1});
    }

    // output
    cout << N * N - A.size() << endl;
    return 0;
}
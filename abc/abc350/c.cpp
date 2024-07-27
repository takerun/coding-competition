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
    int N;
    cin >> N;
    vector<int> A(N, 0), pos(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
        pos[A[i]] = i;
    }

    // logic
    vector<pair<int, int>> inv;
    for(int a = 0; a < N; a++) {
        int ai = pos[a];
        if(ai == a) continue;

        inv.push_back({a, ai});
        swap(pos[A[a]], pos[A[ai]]);
        swap(A[a], A[ai]);
    }

    // output
    cout << inv.size() << endl;
    for(int i = 0; i < inv.size(); i++) {
        cout << inv[i].first + 1 << " " << inv[i].second + 1 << endl;
    }
    cout << endl;
    return 0;
}
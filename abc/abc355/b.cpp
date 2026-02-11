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
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> AB(N + M);
    for(int i = 0; i < N; i++) {
        cin >> AB[i].first;
        AB[i].second = 1;
    }
    for(int i = N; i < N + M; i++) {
        cin >> AB[i].first;
        AB[i].second = 0;
    }

    // logic
    sort(begin(AB), end(AB));

    // output
    int prev = AB[0].second;
    for(int i = 1; i < N + M; i++) {
        if(prev * AB[i].second == 1) {
            Yes(true);
            return 0;
        }
        prev = AB[i].second;
    }

    Yes(false);
    return 0;
}
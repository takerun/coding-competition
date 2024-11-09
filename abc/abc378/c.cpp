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
template <class T>
inline bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    fastIO();
    // input
    int N, t;
    cin >> N;
    map<int, int> m;
    vector<int> ans(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> t;
        ans[i] = (m[t] == 0 ? -1 : m[t]);
        chmax(m[t], i + 1);
    }

    // logic

    // output
    for(const auto& a : ans) cout << a << " ";
    cout << endl;
    return 0;
}
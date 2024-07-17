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
    int N;
    cin >> N;
    vector<pair<int, int>> A(N * 2);
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(a > b) swap(a, b);

        A[a] = {0, i};  // 左端
        A[b] = {1, i};  // 右端
    }

    // logic
    stack<int> st;
    for(int i = 0; i < N * 2; i++) {
        auto [f, n] = A[i];
        if(f == 0) {
            st.push(n);
        } else {
            if(st.top() != n) {
                Yes(true);
                return 0;
            }
            st.pop();
        }
    }

    // output
    Yes(false);
    return 0;
}
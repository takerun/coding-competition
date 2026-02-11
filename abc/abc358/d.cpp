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
    priority_queue<int64, vector<int64>, greater<int64>> A, B;
    for(int i = 0; i < N; i++) {
        int64 a;
        cin >> a;
        A.push(a);
    }
    for(int i = 0; i < M; i++) {
        int64 b;
        cin >> b;
        B.push(b);
    }

    // logic
    int64 cost = 0;
    while(!A.empty()) {
        int64 a = A.top();
        A.pop();

        if(B.top() <= a) {
            cost += a;
            B.pop();
            if(B.empty()) {
                cout << cost << endl;
                return 0;
            }
        }
    }

    // output
    cout << -1 << endl;
    return 0;
}
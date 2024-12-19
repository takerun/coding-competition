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
    vector<int> A(N, 0), B(M, 0);
    for(auto &a : A) cin >> a;
    for(auto &b : B) cin >> b;

    // logic
    vector<int> AA;
    map<int, int> v2i;
    int cur;
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            cur = A[0], v2i[cur] = i, AA.push_back(cur);
            continue;
        }

        if(A[i] < cur) cur = A[i], v2i[cur] = i, AA.push_back(cur);
    }
    sort(begin(AA), end(AA));

    // output
    for(int i = 0; i < M; i++) {
        int ii = upper_bound(begin(AA), end(AA), B[i]) - begin(AA);
        if(B[i] < AA[0]) {
            cout << -1 << endl;
        } else {
            cout << v2i[AA[ii - 1]] + 1 << endl;
        }
    }
    return 0;
}
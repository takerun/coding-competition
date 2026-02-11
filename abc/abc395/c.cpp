#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;
template <class T>
inline bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for(int i = 0; i < A.size(); i++) {
        int a;
        cin >> A[i].first;
        A[i].second = i;
    }

    // logic
    sort(begin(A), end(A));
    int ans = numeric_limits<int>::max(), cur = -1, curi = -1;
    for(int i = 0; i < N; i++) {
        if(A[i].first != cur) {
            cur = A[i].first;
            curi = A[i].second;
            continue;
        }
        chmin(ans, A[i].second - curi + 1);
        curi = A[i].second;
    }

    // output
    cout << (ans != numeric_limits<int>::max() ? ans : -1) << endl;
    return 0;
}
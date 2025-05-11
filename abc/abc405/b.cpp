#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;
template <class T>
inline bool chmax(T& a, T b) {
    if(a < b) {
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
    int N, M;
    cin >> N >> M;
    vector<int> A(N, 0);
    vector<bool> exist(M, false);
    vector<int> topA(M, 0);
    for(int i = 0; i < A.size(); i++) {
        cin >> A[i], A[i]--;
        if(!exist[A[i]]) {
            exist[A[i]] = true;
            topA[A[i]] = i;
        }
    }

    // logic
    bool all{true};
    vector<bool> tf;
    for(int i = 0; i < M; i++) {
        if(!exist[i]) {
            all = false;
            break;
        }
    }
    if(!all) {
        cout << 0 << endl;
        return 0;
    }
    int mx = numeric_limits<int>::min();
    for(int i = 0; i < M; i++) chmax(mx, topA[i]);
    auto maxit = max_element(begin(topA), end(topA));

    // output
    cout << N - *maxit << endl;
    return 0;
}
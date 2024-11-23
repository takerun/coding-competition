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
    vector<int64> pos(M, 0LL), val(M, 0LL);
    for(auto &a : pos) {
        cin >> a;
        a--;
    }
    for(auto &a : val) cin >> a;
    vector<pair<int64, int64>> A(M);
    for(int i = 0; i < M; i++) {
        A[i] = {pos[i], val[i]};
    }
    auto order = [](const auto &left, const auto &right) {
        // 第一要素が同値なら、第二要素で降順
        if(left.first == right.first)
            return left.second > right.second;
        else  // 第一要素で昇順
            return left.first < right.first;
    };
    sort(begin(A), end(A), order);

    // logic
    int64 notL = 0LL, ans = 0LL;
    for(int64 i = 0; i < M; i++) {
        if(A[i].first > notL) {
            cout << -1 << endl;
            return 0;
        }
        ans += (notL - A[i].first + notL - A[i].first + A[i].second - 1) *
               A[i].second / 2;
        // cout << ans << endl;
        notL += A[i].second;
    }

    // output
    if(notL != N) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
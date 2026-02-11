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
    int64 N;
    cin >> N;
    vector<pair<int64, int64>> A(N);
    for(auto &a : A) {
        cin >> a.first >> a.second;
    }

    // logic
    sort(begin(A), end(A));
    auto first_less = [](const auto &mid, const auto &pr) {
        return mid < pr.first;
    };
    int64 ans = 0LL;
    for(int64 i = 0; i < N; i++) {
        int64 l = A[i].first, r = A[i].second;

        int64 ri = upper_bound(begin(A), end(A), r, first_less) - begin(A);
        ans += (N - i - 1) - (N - ri);
    }

    // output
    cout << ans << endl;
    return 0;
}
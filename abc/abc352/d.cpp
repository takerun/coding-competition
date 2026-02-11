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

#include <atcoder/segtree>
using S = int;
S op(S a, S b) { return max(a, b); }
S e() { return INT_MIN; }
using segmax = atcoder::segtree<S, op, e>;
using T = int;
T op2(T a, T b) { return min(a, b); }
T e2() { return INT_MAX; }
using segmin = atcoder::segtree<T, op2, e2>;

int main() {
    fastIO();
    // input
    int N, K, p;
    cin >> N >> K;
    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> p;
        A[i].first = p;
        A[i].second = i;
    }

    // logic
    auto order = [](const auto &left, const auto &right) {
        if(left.first == right.first)
            return left.second < right.second;
        else
            return left.first < right.first;
    };
    sort(begin(A), end(A), order);
    vector<int> Ai(N);
    for(int i = 0; i < N; i++) {
        Ai[i] = A[i].second;
    }

    // output
    segmax segmx(Ai);
    segmin segmn(Ai);
    int mn = INT_MAX;
    for(int i = 0; i <= N - K; i++) {
        mn = min(mn, segmx.prod(i, i + K) - segmn.prod(i, i + K));
    }
    cout << mn << endl;
    return 0;
}
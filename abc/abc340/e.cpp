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

#include <atcoder/lazysegtree>
using S = int64;                           // モノイドの型
S op(S a, S b) { return max(a, b); }       // 取得演算: max(a,b), min(a,b)
S e() { return INT_MIN; }                  // 単位元: -INF, INF
using F = int64;                           // 操作の型
S mapping(F f, S x) { return f + x; }      // 操作演算:
F composition(F f, F g) { return f + g; }  // 写像の合成:
F id() { return 0; }                       // 恒等写像:
using lazy_segtree =
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

int main() {
    fastIO();
    // input
    int N, M;
    cin >> N >> M;
    vector<S> A(N, 0);
    for(S &a : A) cin >> a;

    // logic
    lazy_segtree seg(A);
    for(int i = 0; i < M; i++) {
        int64 b;
        cin >> b;
        int64 bn = seg.get(b);
        seg.set(b, 0);
        seg.apply(0, N, bn / N);
        int64 r = (bn % N);
        if(b + r >= N) {
            seg.apply(b + 1, N, 1);
            seg.apply(0, b + r - N + 1, 1);
        } else {
            seg.apply(b + 1, b + r + 1, 1);
        }
    }

    // output
    for(int i = 0; i < N; i++) {
        cout << seg.get(i) << " ";
    }
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;
// https://atcoder.github.io/ac-library/document_en/lazysegtree.html
// https://betrue12.hateblo.jp/entry/2020/09/23/005940
#include <atcoder/lazysegtree>
// 区間加算、区間最大値
using S = int64;                            // モノイドの型
S op(S a, S b) { return max(a, b); }        // 取得演算: max(a,b), min(a,b)
S e() { return numeric_limits<S>::min(); }  // 単位元: -INF, INF
using F = int64;                            // 操作の型
S mapping(F f, S x) { return f + x; }       // 操作演算:
F composition(F f, F g) { return f + g; }   // 写像の合成:
F id() { return 0; }                        // 恒等写像:
using lazy_segtree =
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
// usage pattern 1:
// lazy_segtree seg(N);
// 区間加算、区間和取得
// struct S {
//     int64 value;
//     int size;
// };
// using F = int64;
// S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
// S e() { return {0, 0}; }
// S mapping(F f, S x) { return {x.value + f * x.size, x.size}; }
// F composition(F f, F g) { return f + g; }
// F id() { return 0; }
// using lazy_segtree =
//     atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
// usage pattern 2:
// vector<S> v(N, {0, 1, 2});
// lazy_segtree seg(v);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int64 N;
    cin >> N;
    vector<int64> A(N, 0LL);
    for(int i = 0; i < A.size(); i++) cin >> A[i];

    // logic
    lazy_segtree seg(A);
    for(int i = 0; i < N - 1; i++) {
        int64 Ai = seg.get(i);
        seg.apply(i + 1, min(N, i + 1 + Ai), 1);
        seg.set(i, max(Ai - N + i + 1, 0LL));
    }

    // output
    for(int i = 0; i < A.size(); i++)
        cout << seg.get(i) << endlif(i == A.size() - 1);
    return 0;
}

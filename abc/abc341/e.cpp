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
// https://atcoder.github.io/ac-library/document_en/lazysegtree.html
// https://betrue12.hateblo.jp/entry/2020/09/23/005940
#include <atcoder/lazysegtree>
struct S {
    int zero;
    int one;
    string first;
    string last;
    bool good;
};  // モノイドの型
S op(S a, S b) {
    return {a.zero + b.zero, a.one + b.one, a.first, b.last,
            a.good && b.good && !(a.last == b.first)};
}  // 取得演算
S e() { return {0, 0, "", "", true}; }  // 単位元
using F = bool;                         // 操作の型
S mapping(F f, S x) {
    return f ? S(x.one, x.zero, x.first == "0" ? "1" : "0",
                 x.last == "0" ? "1" : "0", x.good)
             : x;
}  // 操作演算:
F composition(F f, F g) { return f ? !g : g; }  // 写像の合成:
F id() { return false; }                        // 恒等写像:
using lazy_segtree =
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;
// 使い方
// lazy_segtree seg(N);

int main() {
    fastIO();
    // input
    int N, Q;
    cin >> N >> Q;
    string Str;
    cin >> Str;

    // logic
    vector<S> V;
    for(int i = 0; i < N; i++) {
        if(Str[i] == '0') {
            V.emplace_back(S(1, 0, "0", "0", true));
        } else {
            V.emplace_back(S(0, 1, "1", "1", true));
        }
    }
    lazy_segtree seg(V);
    for(int i = 0; i < Q; i++) {
        int q, l, r;
        cin >> q >> l >> r;
        if(q == 1) {
            seg.apply(l - 1, r, true);
        } else {
            cout << (seg.prod(l - 1, r).good ? "Yes" : "No") << endl;
        }
    }

    // output
    cout << endl;
    return 0;
}
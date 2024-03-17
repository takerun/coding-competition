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

// https://atcoder.github.io/ac-library/production/document_en/segtree.html
#include <atcoder/segtree>
int op(int a, int b) { return max(a, b); }  // 演算: a+b, a*b, max(a,b)
int e() { return 0; }                       // 単位元: 0, 1, 0
using segtree = atcoder::segtree<int, op, e>;

int main() {
    fastIO();
    // input
    int N, D, Amax = 500010;
    cin >> N >> D;
    vector<int> A(N, 0);
    for(int &a : A) cin >> a;

    // logic
    segtree seg(Amax);
    for(int a : A) {
        int l = max(0, a - D);
        int r = min(Amax - 1, a + D);
        int mx = seg.prod(l, r + 1);
        seg.set(a, mx + 1);
    }

    // output
    cout << seg.all_prod();
    cout << endl;
    return 0;
}
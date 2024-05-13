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
// https://atcoder.github.io/ac-library/production/document_ja/fenwicktree.html
#include <atcoder/fenwicktree>
using fenwick_tree = atcoder::fenwick_tree<int>;

int main() {
    fastIO();
    // input
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for(int &a : A) {
        cin >> a;
        a--;
    }

    // logic
    // 転倒数を求めたい配列はA(0-indexed)とする。
    fenwick_tree bit(N);
    int64 inv = 0;
    for(int i = 0; i < N; i++) {
        inv += i - bit.sum(0, A[i] + 1);
        bit.add(A[i], 1);
    }
    // O(N^2)の求め方
    // int inv = 0;
    // for(int i = 0; i < N; i++)
    //     for(int j = 0; j < N; j++)
    //         if(i < j && A[i] > A[j]) inv++;

    // output
    cout << inv;
    cout << endl;
    return 0;
}
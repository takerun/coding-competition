#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;
// https://atcoder.github.io/ac-library/production/document_en/dsu.html
#include <atcoder/dsu>
using dsu = atcoder::dsu;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int N, M;
    cin >> N >> M;

    // // logic
    vector<int> cnt(N, 0);
    dsu d(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b, a--, b--;
        cnt[a]++;
        cnt[b]++;
        d.merge(a, b);
    }

    // output
    if(N != M) {
        cout << "No" << endl;
        return 0;
    }

    for(int i = 0; i < N; i++) {
        if(cnt[i] != 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    if(N == M and d.groups().size() == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
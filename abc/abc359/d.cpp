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
#include <atcoder/modint>
using mint = atcoder::modint998244353;

int main() {
    fastIO();
    // input
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // logic
    vector<int> cuml(N + 1, 0);
    for(int i = 0; i < N; i++) {
        cuml[i + 1] = cuml[i];
        if(S[i] == '?') cuml[i + 1]++;
    }
    vector<mint> allp(cuml[N] + 1, 1);
    for(int i = 0; i < cuml[N]; i++) {
        allp[i + 1] = allp[i] * 2;
    }

    auto check = [&](string s) { return s == string(rbegin(s), rend(s)); };

    string stemp;
    mint ntemp;
    auto dfs = [&](auto &&self, const int idx) -> void {
        if(idx == K) {
            if(check(stemp)) ntemp += 1;
            cout << stemp << endl;
            return;
        }

        if(stemp[idx] == '?') {
            stemp[idx] = 'a';
            self(self, idx + 1);
            stemp[idx] = 'b';
            self(self, idx + 1);
            stemp[idx] = '?';
        } else {
            self(self, idx + 1);
        }
        return;
    };

    stemp = "????";
    ntemp = 0;
    dfs(dfs, 0);
    cout << ntemp.val() << endl;

    // mint all = allp[cuml[N]];
    // for(int i = 0; i < N - K + 1; i++) {
    //     int qqnum = cuml[i + K] - cuml[i];
    //     for(int j = i; j < i + K; j++) {
    //         // logic
    //     }
    // }

    // output

    return 0;
}
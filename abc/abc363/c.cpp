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
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // logic
    vector<int> P;
    for(int i = 0; i < N; i++) {
        P.emplace_back(i);
    }

    set<string> done;
    int64 ans = 0;
    do {
        string s = "", subs;
        for(int i = 0; i < N; i++) {
            // logic
            int p = P[i];
            s += S[P[i]];
        }
        if(done.count(s) != 0)
            continue;  // Sの重複込みの配列をnext_permutationすれば、重複の削除は不要
        done.insert(s);

        bool aa = true;
        for(int i = 0; i < N - K + 1; i++) {
            subs = s.substr(i, K);
            bool flag = true;
            for(int j = 0; j < K; j++) {
                if(s[i + j] != s[i + K - 1 - j]) flag = false;
            }
            if(flag) aa = false;
        }
        if(aa) ans++;
    } while(next_permutation(begin(P), end(P)));

    // output
    cout << ans << endl;
    return 0;
}
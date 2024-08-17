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
    int N;
    cin >> N;
    vector<string> S(N);
    int M = 0;
    for(auto &s : S) {
        cin >> s;
        M = max(M, int(s.size()));
    }

    // logic
    for(int i = 0; i < M; i++) {
        string buf = "";
        for(int j = N - 1; j >= 0; j--) {
            if(i < S[j].size()) {
                buf += S[j][i];
            } else {
                buf += '*';
            }
        }
        while(buf[buf.size() - 1] == '*') buf = buf.substr(0, buf.size() - 1);
        cout << buf << endl;
    }

    // output

    return 0;
}
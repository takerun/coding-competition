#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // logic
    for(int i = 1; i < N; i++) {
        if(S[i] == '?' and (S[i - 1] == 'o')) S[i] = '.';
    }
    for(int i = N - 2; i >= 0; i--) {
        if(S[i] == '?' and (S[i + 1] == 'o')) S[i] = '.';
    }
    vector<pair<int, int>> pos_len;
    int conti = 0, pos_buf = -1, maxo = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '?') {
            if(conti == 0) {
                pos_buf = i;
            }
            conti++;
        } else {
            if(conti != 0) {
                pos_len.push_back({pos_buf, conti});
                maxo += (conti + 1) / 2;
            }
            conti = 0;
        }
        if(S[i] == 'o') maxo++;
    }
    if(conti != 0) {
        pos_len.push_back({pos_buf, conti});
        maxo += (conti + 1) / 2;
    }

    // output
    if(maxo > K) {
        cout << S << endl;
    } else {
        for(int i = 0; i < pos_len.size(); i++) {
            if(pos_len[i].second % 2 == 1) {
                bool flag = true;
                for(int j = pos_len[i].first;
                    j < pos_len[i].first + pos_len[i].second; j++) {
                    S[j] = flag ? 'o' : '.';
                    flag = !flag;
                }
            }
        }
        cout << S << endl;
    }
    return 0;
}
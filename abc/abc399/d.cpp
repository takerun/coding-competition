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
    int T;
    cin >> T;

    // logic
    for(int t = 0; t < T; t++) {
        int N;
        cin >> N;
        vector<int> A(2 * N, 0);
        vector<vector<int>> pos(N);
        vector<bool> nei(N, false);
        vector<bool> done(N, false);
        for(int i = 0; i < A.size(); i++) {
            cin >> A[i], A[i]--;
            pos[A[i]].push_back(i);
            if(pos[A[i]].size() == 2 and pos[A[i]][1] - pos[A[i]][0] == 1) {
                nei[A[i]] = true;
            }
        }

        // judge
        int ans = 0LL;
        for(int i = 0; i < A.size() - 1; i++) {
            if(nei[A[i + 1]]) {
                done[A[i]] = true;
                continue;
            }
            if(done[A[i]]) continue;

            if(done[A[i + 1]]) {
                done[A[i]] = true;
                continue;
            }

            if(pos[A[i]][1] == pos[A[i + 1]][1] - 1 or
               pos[A[i]][1] == pos[A[i + 1]][1] + 1) {
                ans++;
                done[A[i]] = true;
            }
        }
        cout << ans << endl;
        // for(int i = 0; i < pos.size(); i++)
        //     cout << pos[i][0] << " " << pos[i][1] << endl;
    }

    // output

    return 0;
}
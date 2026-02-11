#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;
template <class T>
inline bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int N, M, K;
    cin >> N >> M;
    vector<vector<int>> Mat(M, vector<int>());
    for(int i = 0; i < M; i++) {
        cin >> K;
        int mat;
        for(int j = 0; j < K; j++) {
            cin >> mat, mat--;
            Mat[i].push_back(mat);
        }
    }
    vector<int> B(N, 0), Bi(N, 0);
    for(int i = 0; i < B.size(); i++) {
        cin >> B[i], B[i]--;
        Bi[B[i]] = i;
    }

    // logic
    vector<int> Add(N, 0);
    for(int i = 0; i < M; i++) {
        int maxBi = -1;
        for(int j = 0; j < Mat[i].size(); j++) {
            chmax(maxBi, Bi[Mat[i][j]]);
        }
        Add[maxBi]++;
    }

    // output
    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans += Add[i];
        cout << ans << endl;
    }
    return 0;
}
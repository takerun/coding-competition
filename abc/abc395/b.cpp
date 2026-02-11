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
    int N;
    cin >> N;
    vector<vector<int>> Mat(N, vector<int>(N, 0));

    // logic
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N - i; j++) {
            for(int k = i; k < N - i; k++) {
                int ii = i % 2;
                Mat[j][k] = ii;
            }
        }
    }

    // output
    for(int i = 0; i < Mat.size(); i++) {
        for(int j = 0; j < Mat[i].size(); j++) {
            cout << (Mat[i][j] == 0 ? '#' : '.');
        }
        cout << endl;
    }
    return 0;
}
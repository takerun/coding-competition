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
    vector<vector<int>> graph(N), rgraph(N);
    vector<string> C(N);
    for(int i = 0; i < N; i++) {
        cin >> C[i];
        for(int j = 0; j < N; j++) {
            if(C[i][j] != '-') {
                graph[i].push_back(j);
                rgraph[j].push_back(i);
            }
        }
    }

    // logic

    // output

    return 0;
}
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
    vector<vector<int>> Aval(N + 1, vector<int>());
    int v;
    for(int i = 0; i < N; i++) {
        cin >> v;
        Aval[v].emplace_back(i);
    }

    // logic
    int base = 0;
    vector<int> imos(N - 1, 0);
    for(int i = 0; i < Aval.size(); i++) {
        if(Aval[i].size() == 0) continue;
        base++;
        imos[Aval[i][0]] += 1;
        imos[Aval[i][Aval[i].size() - 1]] -= 1;
    }

    // simulate
    int cuml = imos[0];
    int mx = cuml;
    for(int i = 1; i < N - 2; i++) {
        cuml += imos[i];
        mx = max(mx, cuml);
    }

    // output
    cout << base + mx << endl;
    return 0;
}
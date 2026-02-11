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
    string N;
    cin >> N;

    // logic
    int Ni = 0;
    for(int i = 0; i < N.size(); i++)
        if(N[i] == '.') Ni = i;
    int Na = stoi(N.substr(0, Ni));
    int Nb = stoi(N.substr(Ni + 1, N.size()));
    if(Na >= 38) {
        cout << 1 << endl;
    } else if(Na == 37 and Nb >= 5) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }

    // output

    return 0;
}
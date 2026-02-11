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
    string S, T;
    cin >> S >> T;

    // logic
    int hum = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] != T[i]) hum++;
    }

    // output
    cout << hum << endl;
    return 0;
}
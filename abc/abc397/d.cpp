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
    int64 N;
    cin >> N;

    // logic
    for(int64 i = 1; i * i * i < N * 4; i++) {
        if(N % i != 0) continue;
        -3 * i* i + (12 * N / i);
    }

    // output

    return 0;
}
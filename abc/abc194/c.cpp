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
    vector<int64> A(N, 0);
    for(int i = 0; i < A.size(); i++) cin >> A[i];

    // logic
    map<int64, int64> ctr;
    for(int i = 0; i < N; i++) {
        ctr[A[i]]++;
    }
    int64 ans = 0LL;
    for(int i = -200; i <= 200; i++) {
        for(int j = i + 1; j <= 200; j++) {
            if(ctr.count(i) != 0 and ctr.count(j) != 0)
                ans += ctr[i] * ctr[j] * (i - j) * (i - j);
        }
    }

    // output
    cout << ans << endl;
    return 0;
}
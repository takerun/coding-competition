#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
typedef long long int int64;

int main() {
    fastIO();
    // input
    int N, K;
    cin >> N >> K;
    vector<int> A(K, 0);
    for(int &a : A) cin >> a;

    // logic
    vector<int> cuml1(K + 1, 0), cuml2(K + 1, 0);
    for(int i = 1; i <= K; i++) {
        cuml1[i] = cuml1[i - 1];
        if(i % 2 == 0) cuml1[i] = cuml1[i - 1] + A[i - 1] - A[i - 2];
    }
    for(int i = K - 1; i >= 0; i--) {
        cuml2[i] = cuml2[i + 1];
        if((K - i) % 2 == 0) cuml2[i] = cuml2[i + 1] + A[i + 1] - A[i];
    }
    int ans = 1e9;
    for(int i = 0; i < K; i += 2) {
        ans = min(ans, cuml1[i] + cuml2[i]);
    }

    // output
    cout << ans;
    cout << endl;
    return 0;
}

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
    int N;
    cin >> N;
    vector<int64> A(N, 0);
    for(int64 &a : A) cin >> a;

    // logic
    int M = int(sqrt(2e5));
    vector<int64> sqnum(M, 0);
    for(int i = 1; i < M; i++) {
        sqnum[i] = (i + 1) * (i + 1);
    }
    for(int i = 0; i < N; i++) {
        for(int j = M - 1; j >= 1; j--) {
            if(A[i] % sqnum[j] == 0) {
                A[i] /= sqnum[j];
            }
        }
    }
    map<int64, int64> cnt;
    for(int i = 0; i < N; i++) {
        cnt[A[i]]++;
    }
    int64 ans = 0;
    for(const auto &[key, val] : cnt) {
        if(key == 0) {
            for(int i = 0; i < val; i++) {
                ans += N - 1 - i;
            }
            continue;
        }

        ans += val * (val - 1) / 2;
    }

    // output
    cout << ans;
    cout << endl;
    return 0;
}
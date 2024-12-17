// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int int64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int N;
    cin >> N;
    int64 S;
    cin >> S;
    vector<int64> A(N, 0LL);
    for(auto &a : A) cin >> a;
    vector<int64> cuml(N * 2 + 1, 0LL);
    for(int i = 0; i < N * 2; i++) cuml[i + 1] = cuml[i] + A[i % N];
    int64 Acycle = cuml[N];

    // logic
    int64 Scycle = S % Acycle;
    if(Scycle == 0) {
        cout << "Yes" << endl;
        return 0;
    }

    int left = 0, right = 0;
    while(left <= N) {
        // optional: keep left < right
        while(left >= right) right++;
        if(right > N * 2) break;

        // slide right pos
        int next_right = right;
        while(++next_right <= N * 2 and cuml[next_right] - cuml[left] <= Scycle)
            right = next_right;

        // calc value
        if(cuml[right] - cuml[left] == Scycle) {
            cout << "Yes" << endl;
            return 0;
        }

        left++;
    }

    // output
    cout << "No" << endl;
    return 0;
}
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
    int64 s, t;
    for(int i = 0; i < N - 1; i++) {
        cin >> s >> t;
        A[i + 1] += (A[i] / s) * t;
    }

    // logic

    // output
    cout << A[N - 1];
    cout << endl;
    return 0;
}
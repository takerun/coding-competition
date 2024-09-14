// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define endl "\n"
void Yes(bool a) { cout << (a ? "Yes" : "No") << endl; }
typedef long long int int64;

int main() {
    fastIO();
    // input
    int64 N;
    cin >> N;
    vector<int64> A(N, 0LL);
    for(auto &a : A) cin >> a;

    // logic
    int64 cnt = 0;

    int left = 0, right = 0;
    while(left < N) {
        // optional: keep left < right
        while(left >= right) right++;
        if(right >= N) break;

        // slide right pos
        int64 diff = A[right] - A[left];
        int next_right = right;
        while(++next_right < N and A[next_right] - A[right] == diff)
            right = next_right;

        // calc score
        int64 length = (right - left);
        cnt += (length + 1LL) * length / 2LL;

        // next left pos
        left = right;

        // end condition
        if(left == N - 1) break;
    }

    // output
    cout << cnt + N << endl;
    return 0;
}
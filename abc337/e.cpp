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
    int M = 1;
    while((1 << M) < N) M++;
    cout << M << endl << flush;

    // logic
    for(int i = 0; i < M; i++) {
        int digit = 1 << i;
        vector<int> buf;
        for(int j = 0; j < N; j++) {
            if(digit & j) {
                buf.emplace_back(j + 1);
            }
        }
        cout << buf.size() << " ";
        for(const auto &b : buf) {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << flush;
    string S;
    cin >> S;
    int ans = 0;
    for(int i = M - 1; i >= 0; i--) {
        ans += (1 << i) * int(S[i] - '0');
    }

    // output
    cout << ans + 1;
    cout << endl;
    return 0;
}

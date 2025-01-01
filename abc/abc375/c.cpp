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
    int N;
    cin >> N;
    vector<string> Mat(N);
    for(int i = 0; i < N; i++) {
        cin >> Mat[i];
    }

    // logic
    auto func = [&](int x, int y, int r) {
        vector<int> next(2);
        if(r % 4 == 0) {
            next[0] = x, next[1] = y;
        } else if(r % 4 == 1) {
            next[0] = y, next[1] = N - 1 - x;
        } else if(r % 4 == 2) {
            next[0] = N - 1 - x, next[1] = N - 1 - y;
        } else {
            next[0] = N - 1 - y, next[1] = x;
        }
        return next;
    };

    vector<string> Ans(N, "");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            Ans[i] += '#';
        }
    }
    vector<int> next;
    for(int i = 0; i < N / 2; i++) {
        // for x
        for(int y = i; y <= N - 1 - i; y++) {
            next = func(i, y, i + 1);
            Ans[next[0]][next[1]] = Mat[i][y];
            next = func(N - 1 - i, y, i + 1);
            Ans[next[0]][next[1]] = Mat[N - 1 - i][y];
        }
        // for y
        for(int x = i; x <= N - 1 - i; x++) {
            next = func(x, i, i + 1);
            Ans[next[0]][next[1]] = Mat[x][i];
            next = func(x, N - 1 - i, i + 1);
            Ans[next[0]][next[1]] = Mat[x][N - 1 - i];
        }
    }

    // output
    for(int i = 0; i < N; i++) {
        cout << Ans[i] << endl;
    }

    return 0;
}
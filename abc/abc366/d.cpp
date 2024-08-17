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

    vector tens(N, vector(N, vector(N, 0LL)));
    vector tcuml(N + 1, vector(N + 1, vector(N + 1, 0LL)));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                cin >> tens[i][j][k];
                tcuml[i + 1][j + 1][k + 1] =
                    tcuml[i + 1][j + 1][k] + tcuml[i + 1][j][k + 1] +
                    tcuml[i][j + 1][k + 1] - tcuml[i + 1][j][k] -
                    tcuml[i][j + 1][k] - tcuml[i][j][k + 1] + tcuml[i][j][k] +
                    tens[i][j][k];
            }
        }
    }
    // usage:
    auto cube_sum = [&](int l0, int r0, int l1, int r1, int l2, int r2) {
        return tcuml[r0][r1][r2] - tcuml[l0][r1][r2] - tcuml[r0][l1][r2] -
               tcuml[r0][r1][l2] + tcuml[l0][l1][r2] + tcuml[l0][r1][l2] +
               tcuml[r0][l1][l2] - tcuml[l0][l1][l2];
    };
    // box_sum(lx, rx, ly, ry, lz, rz);

    // output
    int Q, lx, rx, ly, ry, lz, rz;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        cout << cube_sum(lx - 1, rx, ly - 1, ry, lz - 1, rz) << endl;
    }

    return 0;
}
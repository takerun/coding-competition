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
    int v1, v2, v3;
    cin >> v1 >> v2 >> v3;

    // logic
    using T = int;
    auto volumeCube = [&](T blX1, T blY1, T blZ1, T trX1, T trY1, T trZ1,
                          T blX2, T blY2, T blZ2, T trX2, T trY2, T trZ2) {
        return max(0, min(trX1, trX2) - max(blX1, blX2)) *
               max(0, min(trY1, trY2) - max(blY1, blY2)) *
               max(0, min(trZ1, trZ2) - max(blZ1, blZ2));
    };
    auto volumeCube3 = [&](T blX1, T blY1, T blZ1, T trX1, T trY1, T trZ1,
                           T blX2, T blY2, T blZ2, T trX2, T trY2, T trZ2,
                           T blX3, T blY3, T blZ3, T trX3, T trY3, T trZ3) {
        return max(0, min({trX1, trX2, trX3}) - max({blX1, blX2, blX3})) *
               max(0, min({trY1, trY2, trY3}) - max({blY1, blY2, blY3})) *
               max(0, min({trZ1, trZ2, trZ3}) - max({blZ1, blZ2, blZ3}));
    };

    for(int i2 = -7; i2 <= 7; i2++) {
        for(int j2 = -7; j2 <= 7; j2++) {
            for(int k2 = -7; k2 <= 7; k2++) {
                for(int i3 = -7; i3 <= 7; i3++) {
                    for(int j3 = -7; j3 <= 7; j3++) {
                        for(int k3 = -7; k3 <= 7; k3++) {
                            int v3_temp = volumeCube3(
                                0, 0, 0, 7, 7, 7, i2, j2, k2, i2 + 7, j2 + 7,
                                k2 + 7, i3, j3, k3, i3 + 7, j3 + 7, k3 + 7);
                            int v2_temp =
                                volumeCube(0, 0, 0, 7, 7, 7, i2, j2, k2, i2 + 7,
                                           j2 + 7, k2 + 7) +
                                volumeCube(i2, j2, k2, i2 + 7, j2 + 7, k2 + 7,
                                           i3, j3, k3, i3 + 7, j3 + 7, k3 + 7) +
                                volumeCube(0, 0, 0, 7, 7, 7, i3, j3, k3, i3 + 7,
                                           j3 + 7, k3 + 7) -
                                v3_temp * 3;
                            int v1_temp =
                                7 * 7 * 7 * 3 - v2_temp * 2 - v3_temp * 3;
                            if(v1_temp == v1 && v2_temp == v2 &&
                               v3_temp == v3) {
                                printf("Yes\n0 0 0 %d %d %d %d %d %d\n", i2, j2,
                                       k2, i3, j3, k3);
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    // output
    printf("No\n");
    return 0;
}
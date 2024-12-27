// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int int64;
typedef unsigned long long int uint64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int64 N, M, Sx, Sy;
    cin >> N >> M >> Sx >> Sy;
    map<int64, set<int64>> Xy, Yx;
    for(int i = 0; i < N; i++) {
        int64 x, y;
        cin >> x >> y;
        Xy[x].insert(y);
        Yx[y].insert(x);
    }

    // logic
    int seen = 0;
    for(int i = 0; i < M; i++) {
        char d;
        int64 c;
        cin >> d >> c;
        int64 nx = Sx, ny = Sy;
        if(d == 'R') {
            nx += c;
            if(Yx.count(ny) != 0) {
                auto li = Yx[ny].lower_bound(Sx), ui = Yx[ny].upper_bound(nx);
                auto Li = li;
                for(; li != ui; li++) {
                    Xy[*li].erase(ny);
                    seen++;
                }
                Yx[ny].erase(Li, ui);
            }
        } else if(d == 'L') {
            nx -= c;
            if(Yx.count(ny) != 0) {
                auto li = Yx[ny].lower_bound(nx), ui = Yx[ny].upper_bound(Sx);
                auto Li = li;
                for(; li != ui; li++) {
                    Xy[*li].erase(ny);
                    seen++;
                }
                Yx[ny].erase(Li, ui);
            }
        } else if(d == 'U') {
            ny += c;
            if(Xy.count(nx) != 0) {
                auto li = Xy[nx].lower_bound(Sy), ui = Xy[nx].upper_bound(ny);
                auto Li = li;
                for(; li != ui; li++) {
                    Yx[*li].erase(nx);
                    seen++;
                }
                Xy[nx].erase(Li, ui);
            }
        } else {
            ny -= c;
            if(Xy.count(nx) != 0) {
                auto li = Xy[nx].lower_bound(ny), ui = Xy[nx].upper_bound(Sy);
                auto Li = li;
                for(; li != ui; li++) {
                    Yx[*li].erase(nx);
                    seen++;
                }
                Xy[nx].erase(Li, ui);
            }
        }
        Sx = nx, Sy = ny;
    }
    // output
    cout << Sx << " " << Sy << " " << seen << endl;
    return 0;
}

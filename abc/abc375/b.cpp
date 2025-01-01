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

    // logic
    double ans = 0.0;
    int64 px = 0, py = 0, x, y;
    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        ans += sqrt(abs(x - px) * abs(x - px) + abs(y - py) * abs(y - py));
        swap(px, x);
        swap(py, y);
    }
    ans += sqrt(abs(0 - px) * abs(0 - px) + abs(0 - py) * abs(0 - py));

    // output
    cout << fixed << setprecision(15);
    cout << ans << endl;
    return 0;
}
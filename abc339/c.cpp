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
    vector<int64> cuml(N + 1, 0);
    for(int i = 0; i < N; i++) {
        int64 a;
        cin >> a;
        cuml[i + 1] = cuml[i] + a;
    }

    // logic
    int64 mc = *min_element(begin(cuml), end(cuml));

    // output
    cout << cuml[N] - mc;
    cout << endl;
    return 0;
}

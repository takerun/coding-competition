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
    // vector<int> A(1e6);
    // random_device seed_gen;
    // mt19937 engine(seed_gen());

    // 平均 0, 標準偏差 1 の正規分布
    // normal_distribution<double> dist{0.0, 1.0};
    // auto rng = [&engine, &dist]() { return dist(engine); };
    // generate(A.begin(), A.end(), rng);

    // int N = A.size();
    clock_t start = clock();
    // logic1
    // int mn = INT_MAX;  // 2e9
    // for(int i = 0; i < N; i++) {
    //     mn = min(mn, A[i]);
    // }
    // logic2
    // int mn = 1e9;
    // for(int &a : A) {
    //     mn = min(mn, a);
    // }
    // logic3
    // int mn = *min_element(begin(A), end(A));
    // logic4
    // int mn = 1e9;
    // for(int i : ranges::views::iota(0, int(A.size()))) {
    //     mn = min(mn, A[i]);
    // }
    // logic5
    // int mn = ranges::min(A);
    clock_t end = clock();

    const double time =
        static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    printf("time %lf[ms]\n", time);

    // cout << mn;
    cout << endl;
    return 0;
}
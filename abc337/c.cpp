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
    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[i] = {a, i};
    }

    // logic
    sort(begin(A), end(A));

    auto first_less = [](const auto &pr, const auto &mid) {
        return pr.first < mid;
    };

    // output
    int akey = A[0].second + 1;
    cout << akey << " ";
    for(int i = 0; i < N - 1; i++) {
        int ai = lower_bound(begin(A), end(A), akey, first_less) - begin(A);
        akey = A[ai].second + 1;
        cout << akey << " ";
    }
    cout << endl;
    return 0;
}
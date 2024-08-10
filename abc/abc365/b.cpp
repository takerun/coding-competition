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
    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[i] = {a, i};
    }

    // logic
    auto order = [](const auto &left, const auto &right) {
        if(left.first == right.first)
            return left.second > right.second;
        else
            return left.first > right.first;
    };
    sort(begin(A), end(A), order);

    // output
    cout << A[1].second + 1 << endl;
    return 0;
}
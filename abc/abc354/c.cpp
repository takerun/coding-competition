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
    vector<pair<int64, int>> A(N), C(N);
    for(int i = 0; i < N; i++) {
        int64 a, c;
        cin >> a >> c;
        A[i] = {-a, i};
        C[i] = {c, i};
    }

    // logic
    sort(begin(A), end(A));
    sort(begin(C), end(C));
    queue<int> qCi;
    for(int i = 0; i < N; i++) {
        qCi.push(C[i].second);
    }
    set<int> erasedi;
    vector<int> ans;
    for(int i = 0; i < N; i++) {
        int cani = A[N - 1 - i].second;
        while(erasedi.count(qCi.front()) == 1) {
            qCi.pop();
        }
        if(qCi.front() == cani) {
            ans.push_back(cani + 1);
            qCi.pop();
        } else {
            erasedi.insert(cani);
        }
    }

    // output
    sort(begin(ans), end(ans));
    cout << ans.size() << endl;
    for(const auto &a : ans) cout << a << " ";
    cout << endl;
    return 0;
}
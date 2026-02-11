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
    vector<int> A(N, -1);

    // logic
    int a, c = 0;
    for(int i = 0; i < 2 * N; i++) {
        cin >> a;
        a--;
        if(A[a] == -1) {
            A[a] = i;
        } else {
            if(i - A[a] == 2) c++;
        }
    }

    // output
    cout << c << endl;
    return 0;
}
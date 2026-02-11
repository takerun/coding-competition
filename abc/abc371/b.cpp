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
    int N, M;
    cin >> N >> M;

    // logic
    set<int> ex;
    int a;
    char b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        if(ex.count(a) == 0 and b == 'M') {
            Yes(true);
            ex.insert(a);
        } else {
            Yes(false);
        }
    }

    // output

    return 0;
}
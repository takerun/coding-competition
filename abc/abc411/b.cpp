#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int N;
    cin >> N;
    vector<int> A(N - 1, int{0}), cml(N, int{0});
    for(int i = 0; i < A.size(); i++) cin >> A[i];
    for(int i = 0; i < N - 1; i++) cml[i + 1] = cml[i] + A[i];
    // usage:
    // cml[right] - cml[left]; // sum of [left, right)

    // logic
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            cout << cml[j] - cml[i] << " ";
        }
        cout << endl;
    }

    // output

    return 0;
}
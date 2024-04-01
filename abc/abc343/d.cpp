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
    int N, T;
    cin >> N >> T;
    vector<int64> A(T, 0), B(T, 0), cum(N, 0);
    for(int i = 0; i < T; i++) {
        cin >> A[i] >> B[i];
    }

    // logic
    map<int64, int> mp;
    mp[0] += N;
    for(int i = 0; i < T; i++) {
        mp[cum[A[i] - 1]]--;
        if(mp[cum[A[i] - 1]] == 0) mp.erase(cum[A[i] - 1]);
        cum[A[i] - 1] += B[i];
        mp[cum[A[i] - 1]]++;
        cout << mp.size() << endl;
    }

    // output
    cout << endl;
    return 0;
}
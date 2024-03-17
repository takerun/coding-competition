#include <bits/stdc++.h>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl "\n"
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int int64;


int main() {
	fastIO();
    int64 N, M, T;
    cin >> N >> M >> T;
    vector<int64> a(N), x(M), y(M);
    rep(i, N-1) {
        cin >> a[i];
    }
    rep(i, M) {
        cin >> x[i] >> y[i];
        a[x[i] - 1] -= y[i];
    }

    string ans = "Yes";
    rep(i, N-1) {
        T -= a[i];
        if (T <= 0) {
            ans = "No";
            break;
        }
    }

    cout<<ans;
    cout<<endl;
	return 0;
}
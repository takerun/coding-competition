// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int int64;
typedef unsigned long long int uint64;
#include <atcoder/modint>
using mint = atcoder::modint998244353;

struct Eratos {
    vector<bool> isprime;
    vector<int64> primes;
    Eratos(int n) {
        isprime.resize(n, true);
        isprime[0] = false;
        isprime[1] = false;
        for(int64 i = 2; i < n; ++i) isprime[i] = true;
        for(int64 i = 2; i < n; ++i) {
            if(isprime[i]) {
                primes.push_back(i);
                for(int64 j = i * 2; j < n; j += i) isprime[j] = false;
            }
        }
    }
} Er{1000005};

int64 pw(int64 a, int64 n) { return n == 0 ? 1LL : pw(a, n - 1) * a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int64 N;
    cin >> N;

    // logic
    int64 ans = 0LL;
    for(int i = 0; i < Er.primes.size(); i++) {
        int64 p = Er.primes[i];
        if(pw(p, 4) > N) break;

        if(p < 100) {
            if(pw(p, 8) <= N) ans++;
        }

        for(int j = i + 1; j < Er.primes.size(); j++) {
            int64 q = Er.primes[j];
            if(pw(p, 2) * pw(q, 2) <= N) {
                ans++;
            } else {
                break;
            }
        }
    }

    // output
    cout << ans << endl;
    return 0;
}
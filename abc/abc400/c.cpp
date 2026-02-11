#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;
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

vector<pair<int64, int64>> prime_factorize(int64 N) {
    vector<pair<int64, int64>> res;
    for(int64 a = 2; a * a <= N; ++a) {
        if(N % a != 0) continue;
        int64 ex = 0;  // 指数

        // 割れる限り割り続ける
        while(N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if(N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int64 N;
    cin >> N;

    // logic
    int64 ans = 0LL;
    int64 twoA = 2LL;
    for(int i = 1; i <= 60; i++) {
        if(twoA > N) break;
        ans++;
        int64 halfN = N / twoA;
        auto f = [&](int64 x) { return x * x <= halfN; };  // 判定問題
        int64 ng = 1e9, ok = 0;                            // 反転も可能
        while(abs(ok - ng) > 1) {
            int64 mid = (ok + ng) / 2;
            if(f(mid))
                ok = mid;
            else
                ng = mid;
        }
        // auto f2 = [&](int64 x) { return x * x <= ok; };  // 判定問題
        // int64 ng2 = 1e9, ok2 = 0;                        // 反転も可能
        // while(abs(ok2 - ng2) > 1) {
        //     int64 mid = (ok2 + ng2) / 2;
        //     if(f2(mid))
        //         ok2 = mid;
        //     else
        //         ng2 = mid;
        // }
        ans += (ok - 1) / 2;
        twoA *= 2;
    }

    // output
    cout << ans << endl;
    return 0;
}
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
    int N, Q;
    cin >> N >> Q;

    // logic
    int a, bef, aft, disp = 0;
    vector<int> A(N, int{0});
    for(int i = 0; i < Q; i++) {
        cin >> a, a--;
        bef = 0;
        for(int j = a - 1; j <= a + 1; j++) {
            if(j < 0 || j >= N) continue;
            bef += A[j];
        }
        A[a] = 1 - A[a];
        aft = 0;
        for(int j = a - 1; j <= a + 1; j++) {
            if(j < 0 || j >= N) continue;
            aft += A[j];
        }
        if(aft == 0) {
            disp--;
        } else if(aft == 1 and bef == 0) {
            disp++;
        } else if(aft == 2 and bef == 3) {
            disp++;
        } else if(aft == 3) {
            disp--;
        }
        cout << disp << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl "\n"
typedef long long int int64;

int main() {
	fastIO();
	int64 H, W, C, Q; cin>>H>>W>>C>>Q;
	int64 t[Q], n[Q], c[Q];
    for (int i=0;i<Q;i++) {
        cin>>t[i]>>n[i]>>c[i];
    }
    
    int64 cAns[C];
    int64 hoccupied = 0, woccupied = 0;
    set<int64> hHistory, wHistory;
    memset(cAns, 0, C*sizeof(cAns[0]));
    for (int i=Q-1;i>=0;i--) {
        if (t[i] == 1) { //行
            auto result = hHistory.insert(n[i]);
            if (result.second == true) { // ノータッチの行である場合
                cAns[c[i]-1] += W - wHistory.size();
            }
        } else { // 列
            auto result = wHistory.insert(n[i]);
            if (result.second == true) { // ノータッチの列である場合
                cAns[c[i]-1] += H - hHistory.size();
            }
        }

    }

    for (int i=0;i<C;i++) {
	    cout<<cAns[i]<<' ';
    }

	return 0;
}
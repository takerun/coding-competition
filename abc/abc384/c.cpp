// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long int int64;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    // logic
    map<int, char> itoa = {{0, 'A'}, {1, 'B'}, {2, 'C'}, {3, 'D'}, {4, 'E'}};
    map<int, int> itos = {{0, a}, {1, b}, {2, c}, {3, d}, {4, e}};
    vector<pair<int, string>> ans;
    int Nbit = 5;
    for(int i = 1; i < (1 << Nbit); i++) {
        vector<int> bit(Nbit);
        int pow = 1;
        for(int j = 0; j < Nbit; j++) {
            bit[j] = (i / pow) % 2;
            pow <<= 1;
        }
        // logic
        int score = 0;
        string name;
        for(int j = 0; j < Nbit; j++) {
            if(bit[j] == 1) {
                name += itoa[j];
                score += itos[j];
            }
        }
        ans.emplace_back(score, name);
    }
    auto order = [](const auto &left, const auto &right) {
        // 第一要素が同値なら、第二要素で昇順
        if(left.first == right.first)
            return left.second < right.second;
        else
            return left.first > right.first;
    };
    sort(begin(ans), end(ans), order);

    // output
    for(int i = 0; i < ans.size(); i++) cout << ans[i].second << endl;
    return 0;
}
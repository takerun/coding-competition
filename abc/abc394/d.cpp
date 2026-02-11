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
    string S;
    cin >> S;

    // logic
    // 0: (), 1: [], 2: <>
    stack<int> bk;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '(') {
            bk.push(0);
        } else if(S[i] == '[') {
            bk.push(1);
        } else if(S[i] == '<') {
            bk.push(2);
        } else if(S[i] == ')') {
            if(bk.empty()) {
                cout << "No" << endl;
                return 0;
            }
            if(bk.top() == 0) {
                bk.pop();
            } else {
                cout << "No" << endl;
                return 0;
            }
        } else if(S[i] == ']') {
            if(bk.empty()) {
                cout << "No" << endl;
                return 0;
            }
            if(bk.top() == 1) {
                bk.pop();
            } else {
                cout << "No" << endl;
                return 0;
            }
        } else if(S[i] == '>') {
            if(bk.empty()) {
                cout << "No" << endl;
                return 0;
            }
            if(bk.top() == 2) {
                bk.pop();
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    // output
    cout << ((bk.size() == 0) ? "Yes" : "No") << endl;
    return 0;
}
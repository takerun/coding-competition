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
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    // logic
    map<char, char> mp;
    for(char i = 'a'; i <= 'z'; i++) {
        mp[i] = i;
    }
    for(int i = 0; i < Q; i++) {
        char c, d;
        cin >> c >> d;
        for(char j = 'a'; j <= 'z'; j++) {
            if(c == mp[j]) mp[j] = d;
        }
    }

    // output
    for(int i = 0; i < N; i++) {
        cout << mp[S[i]];
    }
    cout << endl;
    return 0;
}
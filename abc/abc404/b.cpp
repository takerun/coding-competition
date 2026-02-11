#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define endlif(cond) " \n"[cond]
typedef long long int int64;
typedef unsigned long long int uint64;

vector<string> rotate_right90(vector<string>& S) {
    int N = S.size();
    vector<string> ret(N, string(N, '.'));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) ret[i][j] = S[N - 1 - j][i];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // input
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < S.size(); i++) cin >> S[i];
    vector<string> T(N);
    for(int i = 0; i < T.size(); i++) cin >> T[i];

    // logic
    vector<string> S1 = rotate_right90(S), S2 = rotate_right90(S1),
                   S3 = rotate_right90(S2);

    int dS = 0, dS1 = 1, dS2 = 2, dS3 = 3;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(T[i][j] != S[i][j]) dS++;
            if(T[i][j] != S1[i][j]) dS1++;
            if(T[i][j] != S2[i][j]) dS2++;
            if(T[i][j] != S3[i][j]) dS3++;
        }
    }

    // output
    cout << min(dS, min(dS1, min(dS2, dS3))) << endl;
    return 0;
}
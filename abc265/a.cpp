#include <bits/stdc++.h>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl "\n"
typedef long long int int64;


int main() {
	fastIO();
    int64 X, Y, N;
    cin>>X>>Y>>N;

    if (X*3 > Y) {
        cout<<Y*(N/3) + X*(N%3);
    } else {
        cout<<X*N;
    }

	return 0;
}
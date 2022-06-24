#include <bits/stdc++.h>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl "\n"
typedef long long int int64;

int binarySearch(vector<int64> arr[], int64 size);

int main() {
	fastIO();
    int64 cnt = 0, remainder = 1;

    do {
        remainder = remainder * 26 % 10000007;
        cnt++;
    } while (cnt != 260);

    cout<<remainder;

	return 0;
}
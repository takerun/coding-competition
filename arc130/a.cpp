// #include <bits/stdc++.h>
// using namespace std;

// #define fastIO() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
// #define endl "\n"
// typedef long long int int64;
// int main() {
// 	fastIO();
// 	int64 N;
// 	string str;
// 	cin>>N>>str;
 
// 	int64 sum = 0;
// 	int64 count = 1;
//     for(int64 i=1;i<N;i++) {
//         if(str[i-1]==str[i]) {
//             count++;
// 		} else {
//             sum+=(count*(count-1)/2);
//             count=1;
//         }
//     }
//     if(count>1)
//         sum+=(count*(count-1)/2);
 
// 	cout<<sum<<endl;
// 	return 0;
// }


#include<cstdio>
#include<cstring>
using namespace std;
typedef long int int32;
typedef long long int int64;

const int N=3e5;
char s[N];

int main()
{
	int n; scanf("%d", &n);
	scanf("%s", s);

	int32 sum = 0;
	int32 count = 1;
    for(int i=1;i<n;i++) {
        if(s[i-1]==s[i]) {
            count++;
		} else {
            sum+=(count*(count-1)/2);
            count=1;
        }
    }
    if(count>1)
        sum+=(count*(count-1)/2);

	printf("%ld\n", sum);
	return 0;
}
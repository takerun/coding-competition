#include <bits/stdc++.h>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl "\n"
typedef long long int int64;

int binarySearch(vector<int64> arr[], int64 size);

int main() {
	fastIO();
	string astr,bstr;
    vector<int> a,b;
    int64 Asize, Bsize;
    cin>>astr>>bstr;;
    Asize = astr.size();
    for (int i=0;i<Asize;i++) {
        a.emplace_back(astr[i] - '0');
    }
    Bsize = bstr.size();
    for (int i=0;i<Bsize;i++) {
        b.emplace_back(bstr[i] - '0');
    }

    // pre
    vector<int> lng,shrt;
    int64 Lsize,Ssize;
    if (Asize >= Bsize) {
        Lsize = Asize;
        lng = a;
        Ssize = Bsize;
        shrt = b;
    } else {
        Lsize = Bsize;
        lng = b;
        Ssize = Asize;
        shrt = a;        
    }

    // logic
    vector<int> lngshrt;
    for (int i=Lsize-Ssize;i<Lsize;i++) {
        lngshrt.emplace_back(lng[i]);
    }
    sort(lngshrt.begin(), lngshrt.end());
    sort(shrt.begin(), shrt.end(), greater<int>());


    // output
    if (Asize >= Bsize) {
        a = lng;
        b = shrt;
    } else {
        b = lng;
        a = shrt;
    }
    for (int i=0;i<a.size();i++) {
	    cout<<a[i];
    }
    cout<<endl;
    for (int i=0;i<b.size();i++) {
	    cout<<b[i];
    }

	return 0;
}
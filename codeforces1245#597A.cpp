#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define N 100000 
#define M 1000000007
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--){
    	int a,b;cin>>a>>b;
        if(__gcd(a,b)!=1)cout<<"Infinite\n";
        else cout<<"Finite\n";
    }
    return 0;
}
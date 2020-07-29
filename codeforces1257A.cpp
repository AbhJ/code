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
    	int n,x,a,b;
    	cin>>n>>x>>a>>b;a=abs(a-b);
    	if(a+x>=n-1)cout<<n-1<<"\n";
    	else{
    		cout<<a+x<<"\n";
    	}
    }
    return 0;
}
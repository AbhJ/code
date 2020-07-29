#include <bits/stdc++.h>
#define ll long long int
#define N 100009
#define M 1000000007
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;int t;cin>>t;
    while(t--){
    	int n,n1,n2;cin>>n>>n1>>n2;int x1=0,x2=0,max1=0,max2=0;
    	for (int i = 0; i < n1; ++i)cin>>x1,max1=max(max1,x1);
	    for (int i = 0; i < n2; ++i)cin>>x2,max2=max(max2,x2);
	    if(max2<max1)cout<<"YES\n";else cout<<"NO\n";
    }
    return 0;   
}
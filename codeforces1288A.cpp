#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 1000100
ll x[N];
ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}
int main()
{
    ibs;cti;int t;cin>>t;
    while(t--){
    	int n,d;cin>>n>>d;
    	x[0]=d;int i=1;
    	while(x[i-1]<=x[i-2] or i<2){
    		x[i]=i+d/(i+1);
    		if(d%(i+1))x[i]++;
    		i++;
    	}
    	if(x[i-2]<=n)cout<<"YES\n";else cout<<"NO\n";
    }
    return 0;
}
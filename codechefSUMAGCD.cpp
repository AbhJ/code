	#include <bits/stdc++.h>
	#define ll long long int
	#define ibs ios_base::sync_with_stdio(false)
	#define cti cin.tie(0)
	using namespace std;//coded by abhijay mitra
	ll solve(std::vector<ll> v,ll n){
		sort(v.begin(), v.end());
		if (v[0]==v[n-1]) return 2*v[0];
		ll h=v[n-1],sh=v[n-1],i=n-1,g1=v[0],g2,g3;
		do{
			i--;
			sh=v[i];
		}while(sh==h);
		for (int i = 0; v[i] <sh ; ++i)
			g1=__gcd(g1,v[i]);
		g2=__gcd(g1,h);g3=__gcd(g1,sh);
		if(g3+h>g2+sh)
			return g3+h;
		else return g2+sh;
	}
	int main()
	{
	    ibs;cti;
	    int t;cin>>t;cout<<"\n";
	    while(t--){
	        ll n;cin>>n;std::vector<ll> v(n);
	        for (int i = 0; i < n; ++i)
	        	cin>>v[i];
	        cout<<solve(v,n)<<"\n";
	    }
	    return 0;
	}
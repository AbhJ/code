#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
int main()
{   
    ibs;cti;
    int T;cin>>T;
	while(T--){
		ll a,m,g;cin>>a>>m;g=__gcd(a,m);
		ll x=m/g;ll in=x;
		for (ll i = 2; i <= sqrt(x); ++i)
		{
			if(x%i)continue;
			in-=in/i;
			while(!(x%i))x/=i;//removing the common factor
		}
		if(x>1)in-=in/x;
		cout<<in<<"\n";
	}
    return 0;
}
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
	int n,p,k;cin>>n>>p;
	for (k = 0; k <=n-k*p ; ++k)
	{
		int x=n-k*p;
		bitset<100> b(x);
		if(b.count()>k)
			continue;
		cout<<k<<"\n";
		return 0;
	}
	cout<<"-1\n";
    return 0;
}
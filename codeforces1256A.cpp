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
		int a,b,n,S;cin>>a>>b>>n>>S;
		int x=min(S/n,a);
		if(b>=S-x*n)cout<<"YES\n";else cout<<"NO\n";
	}
    return 0;
}
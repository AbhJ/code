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
	int t;cin>>t;
	while(t--){
		int n,x,ans=0;
		std::map<int, int> m;
		cin>>n>>x;string s;cin>>s;int S=0;
		for (int i = 0; i <n; ++i)
		{
			if(s[i]=='0')S++;
			else S--;
			m[S]++;
		}
		if(!S){
			if(!m[x])ans=0;//impossible case
			else ans=-1;//ans valid for all strings pasted
		}
		else for (auto i:m)
			if((x-i.first)%S==0 and (x-i.first)/S>=0)
				ans+=i.second;
		if(!x and S)ans++;
		cout<<ans<<"\n";
	}
    return 0;
}
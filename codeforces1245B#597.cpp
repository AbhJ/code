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
    	int n;cin>>n;std::vector<int> v(3),r(3,0);
    	cin>>v[0]>>v[1]>>v[2];
    	string s;cin>>s;
    	for (int i = 0; i < n; ++i)
    	{
    		if(s[i]=='R') r[0]++;
    		if(s[i]=='P') r[1]++;
    		if(s[i]=='S') r[2]++;
    	}
    	int score=min(r[0],v[1])+min(r[1],v[2])+min(r[2],v[0]);
    	if(score<<1<n){cout<<"NO\n";continue;}
    	else cout<<"YES\n";
    	std::vector<char> f(n,'X');
    	for (int i = 0; i < n; ++i)
    	{
    		if(s[i]=='R' and v[1] and r[0])v[1]--,r[0]--,f[i]='P';
    		if(s[i]=='P' and v[2] and r[1])v[2]--,r[1]--,f[i]='S';
    		if(s[i]=='S' and v[0] and r[2])v[0]--,r[2]--,f[i]='R';
    	}
    	for (int i = 0; i < n; ++i)
    	{
    		if(f[i]!='X')continue;
    		if(v[0])v[0]--,f[i]='R';
    		else if(v[1])v[1]--,f[i]='P';
    		else if(v[2])v[2]--,f[i]='S';
    	}
    	for (int i = 0; i < n; ++i)
    	{
    		cout<<f[i];
    	}
    	cout<<"\n";
    }
    return 0;
}
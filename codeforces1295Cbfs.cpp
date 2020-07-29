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
	string s,t;
	while(T--){
		cin>>s>>t;
		int count=0,j=0,n=t.length(),m=s.length();bool c=0;
		string x="";
		while(j<n){
			c=0;int j1=j,i1=0;
			while(j<j1+t.length()){
				if(t[j]==x[i1])
					j++;
				else break;
				i1++;
			}
			if(j==j1+t.length())count++;
			for (int i = 0; i < m; ++i)
			{
				if(t[j]==s[i]){
					x+=t[j];
					j++;c=1;
				}
			}
			count++;
			if(!c){cout<<"-1\n";break;}
		}
		if(c)cout<<count<<"\n";
	}
    return 0;
}
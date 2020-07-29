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
		string s;cin>>s;std::vector<int> v(26,0),c(26,0);char x='A';
		int count=0;
		while(!s.empty()){
			if(c[s.back()-'a']==0 and v[s.back()-'a']==1 and x!=s.back())
				c[s.back()-'a']=1;
			if(s.back()!=x)count=1;
			else count++;
			if(v[s.back()-'a']==0 and count%2){
				v[s.back()-'a']=1;
			}
			if(v[s.back()-'a']==1 and !(count%2) and count>1 and !c[s.back()-'a']){
				v[s.back()-'a']=0;
			}
			x=s.back();
			s.pop_back();
		}
		for (int i = 0; i < 26; ++i)
		{
			if(!v[i])continue;
			if(v[i])cout<<(char)(i+'a');
		}
		cout<<"\n";
	}
    return 0;
}
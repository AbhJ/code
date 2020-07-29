#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;int t;cin>>t;
    while(t--){
      string s;cin>>s;std::vector<int> v;int count=0;
      for (int i = 0; i < s.length(); ++i)
      {
        if(s[i]=='o'){
          if((s[i+1]=='n' and s[i+2]=='e')and(s[i-1]=='w' and s[i-2]=='t'))count ++,v.pb(i);
        }
        if(s[i]=='o'){
          if((s[i+1]=='n' and s[i+2]=='e')and!(s[i-1]=='w' and s[i-2]=='t'))count ++,v.pb(i+1);
        }
        if(s[i]=='o'){
          if(!(s[i+1]=='n' and s[i+2]=='e')and(s[i-1]=='w' and s[i-2]=='t'))count ++,v.pb(i-1);
        }
      }
      cout<<count<<"\n";
      for (int i = 0; i < v.size(); ++i)
      {
        cout<<v[i]+1<<" ";
      }
      cout<<"\n";
    }
    return 0;   
}
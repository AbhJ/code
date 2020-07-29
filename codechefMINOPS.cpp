#include <bits/stdc++.h>
// #include <xeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  string s,r;cin>>s>>r;int n=s.length();
  int g=0,k=0,st=-1;ll l=0;
  std::vector<int> gap;
  for (int i = 0; i <= n; ++i)
  {
    if((s[i]!=r[i])){
      l++;
      if(g and st)gap.pb(g);g=0;
    }
    else {g++;if(g==1)st=i;}
  }
  s+='#',r+='#';
  for (int i = 0; i <= n; ++i)
  {
    if(s[i]!=r[i])k++;
    while(i!=n and s[i]!=r[i])i++;
  }
  sort(gap.begin(), gap.end());
  ll ans=l*k;
  for (auto i:gap)
  {
    if(k==1)break;
    k--;l+=i;
    ans=min(ans,l*k);
  }
  cout<<ans;
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    }
    return 0;
}
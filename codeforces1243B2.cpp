#include <bits/stdc++.h>
// #include <numeric>
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
int a[26];vector<pair<int,int>> v;
void solve(){
  int n;string s,t;
  cin>>n>>s>>t;
  if(s==t){cout<<"Yes\n0";return;}
  memset(a,0,sizeof(a));
  for (int i = 0; i < n; ++i)
  {
    a[s[i]-'a']++,a[t[i]-'a']++;
  }
  for (int i = 0; i < 26; ++i)
  {
    if(a[i]%2){cout<<"No";return;}
  }
  cout<<"Yes\n";
  int x=0;
  v.clear();
  // while(s!=t){
    for (int i = 0; i < n; ++i)
    {
      if(s[i]!=t[i])
      for(int j=i+1;j<n;j++)
        if(s[i]==s[j]){swap(s[j],t[i]),v.pb({j,i});break;
      }
      if(s[i]!=t[i])
      for(int j=i+1;j<n;j++)
        if(s[i]==t[j]){swap(t[j],s[j]),v.pb({j,j}),v.pb({j,i});swap(t[i],s[j]);break;
      }
    }
  // }
  cout<<v.size();
  for(auto i:v)cout<<"\n"<<i.F+1<<" "<<i.S+1;
  // cout<<s<<" "<<t;
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      cout<<"\n";
    }
    return 0;
}
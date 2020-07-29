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
void solve(){
  int n;string s,t;
  cin>>n>>s>>t;
  if(s==t){cout<<"No";return;}
  // memset(a,0,sizeof(a));
  std::vector<int> v[2][26];
  for (int i = 0; i < n; ++i)
  {
    v[0][s[i]-'a'].pb(i),v[1][t[i]-'a'].pb(i);
  }
  for (int i = 0; i < 26; ++i)
  {
    sort(v[0][i].begin(), v[0][i].end());
    sort(v[1][i].begin(), v[1][i].end());
  }
  for (int i = 0; i < 26; ++i)
  {
    if(v[0][i].empty())continue;
    if(v[0][i]==v[1][i])continue;
    // cout<<i;
    bool c=0;
    for (int j = 0; j < 26; ++j)
    {
      if(i==j)continue;
      if(v[1][j].empty())continue;
      // cout<<i<<" "<<j;
      if(v[0][i]==v[1][j]){
        if(v[0][i].size()==2){/*cout<<"hi";*/swap(s[v[0][i][0]],t[v[0][i][1]]);c=1;}
      }
      // else c=1;
      // break;
    }
    if(c)break;
  }
  if(s==t){cout<<"Yes";return;}
  std::vector<int> d;
  for (int i = 0; i < n; ++i)
  {
    if(s[i]!=t[i])d.pb(i);
  }
  if(d.size()!=2){cout<<"No";return;}
  int a=d[0],b=d[1];
  swap(s[a],t[b]);
  if(s==t){cout<<"Yes";return;}
  cout<<"No";
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
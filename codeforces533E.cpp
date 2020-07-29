#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=5e3+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int i,j,ans=0,n;
void f(string s,string t){
  for (i = 1; i <=n ; ++i)
  {
    if(s[i]!=t[i])break;
  }
  for (j = n; j ; --j)
  {
    if(s[j]!=t[j])break;
  }
  // if(i==j){ans++;return;}
  if(s.substr(i+1,j-i)==t.substr(i,j-i))ans++;
}
void solve(){
  cin>>n;string s,t;cin>>s>>t;
  s='#'+s;t='#'+t;
  f(s,t),f(t,s);
  cout<<ans;
}
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    // }
    return 0;
}
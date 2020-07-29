#include <bits/stdc++.h>
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
int n,m,dp[2][N];
void f(string s,string t,bool x){
  n=s.length(),m=t.length();
  s='#'+s,t='#'+t;
  int j=n+1;
  for (int i = m; i; --i)
  {
    while(s[--j]!=t[i]);
    dp[x][i]=j;
  }
}
void solve(){
  string s,t;
  cin>>s>>t;
  f(s,t,0);
  reverse(s.begin(), s.end()),reverse(t.begin(), t.end());
  f(s,t,1);
  int left=0,ans=0;dp[0][m+1]=n+1,dp[1][m+1]=0;
  ans=max(dp[0][1]-1,n-(n-dp[1][1]+1));
  for (int i = 2; i <= m; ++i)ans=max(dp[0][i]-(n-dp[1][m-i+1+1]+1)-1,ans);
  cout<<ans;
}
int main()
{
    ibs;cti;
    solve();
    cout<<"\n";
    return 0;
}
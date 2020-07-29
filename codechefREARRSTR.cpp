#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e3+10;
const ll M = 998244353 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
string s;int n;
int dp[500];
void solve(){
  cin>>s;n=s.length();
  if(n==1){cout<<s;return;}
  s='#'+s;memset(dp,0,sizeof(dp));
  for (int i = 1; i <= n; ++i)
  {
    dp[s[i]]++;
  }
  for (int i =1; i <=n; ++i)
  {
    int ma=0,p=0;
    for(int j=0;j<500;j++)
      if(dp[j]>ma and j!=s[i-1])ma=dp[j],p=j;
    if(ma==0){cout<<-1;return;}
    dp[p]--;
    s[i]=p;
  }
  cout<<s.substr(1);
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
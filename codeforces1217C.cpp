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
int n,i,j;ll ans;
int dp[N];
void solve(){
  string s;cin>>s;n=s.length();s='#'+s;
  ans=0;
  // Below is O(n)algorithm
  for(int i=n;i;i--){if(s[i]=='1')dp[i]=i;else dp[i]=dp[i+1];}
  for (int i = 1; i <= n; ++i)
  {
    ll x=0;
    for(int j=dp[i];j<=n;j++){
      ll len=j-i+1;
      x=(x<<1)+(dp[j]==j);
      if(x==len)ans++;else if(x>len)break;
    }
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
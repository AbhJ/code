#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e7+3;
const int M = 1000000007; // modulo
ll dp[1000][1000];
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
vector<int> fact(int n)
{
    vector<int> v;
    for(int i=1;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            v.push_back(i);
            if(i*i!=n)
                v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    return v;
}
//using manacher's algorithm
void solve(){
      int n,m;cin>>n>>m;std::vector<int> S(m);
      for(int i=0;i<m;i++)cin>>S[i];
      for (int i = 0; i < m+1; ++i)dp[0][i]=1;
      for (int i = 1; i <= n; ++i)
      {
        for (int j = 0; j < m; ++j)
        {
          ll x=0,y=0;
          if(i>=S[j])x=dp[i-S[j]][j];
          if(j)dp[i][j]=x+dp[i][j-1];
          else dp[i][j]=x;
        }
      }
      cout<<dp[n][m-1];
}
int main()
{   
    ibs;cti;
    solve();
    cout<<"\n";
    return 0;
}
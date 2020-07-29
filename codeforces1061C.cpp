#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e7+3;
const int M = 1000000007; // modulo
ll dp[N+1];
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
void solve(){
      ll n;cin>>n;std::vector<ll> v(n+1,0);
      for (int i = 1; i <= n; ++i)cin>>v[i];
      dp[0]=1;
      for (int i = 1; i <= n; ++i)
      {
        std::vector<int> V=fact(v[i]);
        for (int j = 0; j < V.size(); ++j)
        {
          dp[V[j]]+=dp[V[j]-1];
          dp[V[j]]%=M;
        }
      }
      ll ans=0;
      for (int i = 1; i <= n; ++i)ans+=dp[i],ans%=M;
      cout<<ans;
}
int main()
{   
    ibs;cti;
    solve();
    cout<<"\n";
    return 0;
}
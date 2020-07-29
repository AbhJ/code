#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
bool u[N];
vector<vector<int > > a;
// void bfs(int s) {
//   d[s] = 0;
//   queue<int> q;
//   q.push(s);
//   while (!q.empty()) {
//     int v = q.front();q.pop();
//     for (auto to : a[v]) {
//       if (d[to] == -1) {
//         d[to] = d[v] + 1;
//         q.push(to);
//       }
//     }
//   }
// }
ll ans;
ll dp[N];
void dfs(int u,int v=-1){
    dp[u]=0;bool x=0;
    // ans=max(ans,d);
    // if(u[x])return;
    // u[x]=1;
    // if(st)c[x]=i+1;
    for(auto b:a[u]){
        // int y=b.F;ll C=b.S;
        if(b==v)continue;
        x=1;dfs(b,u);dp[u]+=dp[b];
    }
    if(!x)dp[u]=1;
}

// ll powM(ll b, int p) {
//   ll r=1;
//   for(; p; b=b*b%M, p/=2)
//     if(p&1)
//       r=r*b%M;
//   return r;
// }
// ll powM(ll a,ll b)
// {
//   ll ans=1;
//   while(b)
//   {
//     if(b&1LL)ans=ans*a%M;
//     a=a*a%M;
//     b>>=1;
//   }
//   return ans;
// }
void solve(){
  int n;cin>>n;
  a=std::vector<std::vector<int > > (n);
  std::vector<int> v(n);
  for (int i = 1; i < n; ++i)
  {
    int u;cin>>u;u--;
    a[u].pb(i),a[i].pb(u);
  }
  dfs(0);
  sort(dp,dp+n);
  for (int i=0;i<n;i++)
  {
    cout<<dp[i]<<" ";
  }
}
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}
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
ll c[N],A[N];
// bool u[N];
vector<vector<int> > a;
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
ll ans=INT_MIN;
ll dp[N];
void dfs(int u,int v=-1){
    // ll d=c[u];
    // ans=max(ans,d);
    // if(u[x])return;
    // u[x]=1;
    // if(st)c[x]=i+1;
    c[u]=A[u];
    dp[u]=INT_MIN;
    for(auto y:a[u]){
        // int y=b.F;ll C=b.S;
        if(y==v)continue;
        dfs(y,u);
        c[u]+=c[y];
        if(dp[u]!=INT_MIN)ans=max(ans,dp[u]+dp[y]);
        dp[u]=max(dp[u],dp[y]);
        // ans=max(ans,x+d-C);
        // if(x%=2)ans++;
        // t=max(x,t);
        // d=max(d,win+c[u]-C);
    }
    dp[u]=max(dp[u],c[u]);
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
// ll s,side,x,y;
void solve(){
  int n;cin>>n;
  a=std::vector<std::vector<int> > (n);
  for (int i = 0; i < n; ++i)
  {
    cin>>A[i];
  }
  // std::vector<int> l(n-1),r(n-1);
  for (int i = 0; i < n-1; ++i)
  {
    int x,y;cin>>x>>y;x--,y--;
    a[x].pb(y),a[y].pb(x);
  }
  // std::vector<int> v(n);
  // int C=0;
  dfs(0);
  if(ans==INT_MIN)cout<<"Impossible";
  else cout<<ans;
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
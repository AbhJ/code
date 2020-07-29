#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const ll M =  1e9+7; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
// int A[N];
// bool u[N];
// vector<vector<pair<int,int>> > a;
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
// ll ans=INT_MIN;
// ll dp[N];
// int dfs(int u,int v=-1){
//     // ll d=c[u];
//     // ans=max(ans,d);
//     // if(u[x])return;
//     // u[x]=1;
//     // if(st)c[x]=i+1;
//     if(A[u]<v)return 0;
//     int x=0;
//     for(auto y:a[u]){

//     // if(u==0)cout<<x+1<<"\n";
//         // int y=b.F;ll C=b.S;
//         // if(y.F==v)continue;
//       //second is total value on path
//         x+=dfs(y.F,max(0,y.S+v));
//         // ans=max(ans,x+d-C);
//         // if(x%=2)ans++;
//         // t=max(x,t);
//         // d=max(d,win+c[u]-C);
//     }
//     // dp[u]=max(dp[u],c[u]);
//     return x+1;
// }

ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
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
long long C(long long n,long long r)
{
    long long N=1,R=1;
    for(long long i=1;i<=n;i++) N=N*i%M;
    for(long long i=1;i<=r;i++) R=R*i%M;
    for(long long i=1;i<=n-r;i++) R=R*i%M;
    return (N*powM(R,M-2))%M;
}
void solve(){
  int n,m,t;cin>>n>>m>>t;ll x=0;set<int>s;
    for (int b = 4; b <= n; ++b)
    {
      if(t-b<1)continue;
      if(t-b>m)continue;
      if(s.count(b))continue;
      s.insert(b);
      x+=C(n,b)*C(m,t-b);
    }
    for (int g = 1; g <= m; ++g)
    {
      if(t-g<4)continue;
      if(t-g>n)continue;
      if(s.count(t-g))continue;
      s.insert(t-g);
      x+=C(n,t-g)*C(m,g);
    }
    cout<<x;
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
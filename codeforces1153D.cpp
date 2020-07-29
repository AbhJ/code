#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
bool u[N];
vector<vector<int>> a;
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
int k;int dp[N];
void dfs(int x){
    if(u[x])dp[x]=1e9;
    // if(u[x])return;
    // u[x]=1;
    // if(st)c[x]=i+1;
    for(int y:a[x]){
        dfs(y);
        if(!u[x])dp[x]+=dp[y];
        else dp[x]=min(dp[x],dp[y]);
        // return dfs(y);
    }
    if(a[x].empty())k++,dp[x]=1;
    // return x;
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
  for (int i = 1; i <=n; ++i)
  {
    cin>>u[i];
  }
  a=std::vector<std::vector<int>> (n+3);
  for (int i = 2; i <=n ; ++i)
  {
    int x;cin>>x;a[x].pb(i);
  }
  dfs(1);
  cout<<k-dp[1]+1;
}
int main()
{
    // ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<k;
      cout<<"\n";
    // }
    return 0;
}
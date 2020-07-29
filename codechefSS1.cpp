#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e6+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
// bool u[N];
// vector<vector<pair<int,int> > > a;
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
// ll ans;
ll dp[N];
// ll dfs(int u,int v=-1){
//     ll d=c[u];
//     ans=max(ans,d);
//     // if(u[x])return;
//     // u[x]=1;
//     // if(st)c[x]=i+1;
//     for(auto b:a[u]){
//         int y=b.F;ll C=b.S;
//         if(y==v)continue;
//         ll win=dfs(y,u);
//         ans=max(ans,win+d-C);
//         d=max(d,win+c[u]-C);
//     }
//     return d;
// }

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
   int n,k,temp;  
   cin>>n>>k;
   memset(dp,-1,sizeof(ll)*(n+10));
   for(ll i=0;i<k;i++){
    cin>>temp;
    dp[temp]=0;
   }
   dp[0]=1;
   for(ll i=1;i<=n;i++){
    if(dp[i]!=0){
      if(i==1)
        dp[i]=dp[i-1];
      else if(i==2)
        dp[i]=dp[i-2]+dp[i-1];
      else
        dp[i]=(dp[i-1]%M+dp[i-2]%M+dp[i-3]%M)%M;
    }
      
   }
   cout<<dp[n];
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      cout<<"\n";
    }
    return 0;
}
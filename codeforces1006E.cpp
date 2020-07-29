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
// int u[N];
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
// vector<vector<int>> a;
std::vector<int> v[N],c;
int s[N],f[N],y;
void dfs(int x){
    c.pb(x);s[x]=y++;
    // if(u[x])return;
    // if(st)c[x]=i+1;
    for(int y:v[x])
        dfs(y);
      f[x]=c.size()-1;
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
// bool bfs(int s) {
//   memset(u,0,sizeof(u));
//   queue<int> q;
//   for(int i=1;i<=n;i++){
//     if(u[i])continue;
//     q.push(i);u[i]=1;
//     while (!q.empty()) {
//         int v = q.front();q.pop();
//         for(int j=1;j<=n;j++){
//           if(j!=v and e[j][v]>=s){
//             if(u[j]==0){
//               u[j]=3-u[v];
//               q.push(j);
//             }
//             else if(u[j]!=3 -u[v])return 0;
//           }
//         }
//       }
//   }
//   return 1;
// }
void solve(){
  int n,q;cin>>n>>q;
  for (int i = 0; i < n-1; ++i)
  {
    int x;cin>>x;x--;v[x].pb(i+1);
  }
  for (int i = 0; i < n; ++i)
  {
    sort(v[i].begin(), v[i].end());
  }
  dfs(0);
  while(q--){
    int x,k;cin>>x>>k;x--,k--;
    if(s[x]+k<=f[x])cout<<c[s[x]+k]+1<<"\n";
    else cout<<"-1\n";
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
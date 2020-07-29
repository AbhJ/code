#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e3+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int u[N];
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
// vector<vector<int>> a;
int n;
int A[N],e[N][N];
std::vector<int> v;
// void dfs(int x){
//     if((int)v.size()>k)return;
//     // if(u[x])return;
//     u[x]=1;
//     v.pb(x);
//     // if(st)c[x]=i+1;
//     for(int y:a[x])if(!u[y])
//         dfs(y);
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
bool bfs(int s) {
  memset(u,0,sizeof(u));
  queue<int> q;
  for(int i=1;i<=n;i++){
    if(u[i])continue;
    q.push(i);u[i]=1;
    while (!q.empty()) {
        int v = q.front();q.pop();
        for(int j=1;j<=n;j++){
          if(j!=v and e[j][v]>=s){
            if(u[j]==0){
              u[j]=3-u[v];
              q.push(j);
            }
            else if(u[j]!=3 -u[v])return 0;
          }
        }
      }
  }
  return 1;
}
void solve(){
  cin>>n;
  for (int i =1; i <= n; ++i)
  {
    cin>>A[i];
  }
  for (int i = 1; i <= n; ++i)
  {
    for(int j=1;j<=n;j++)
      if(i!=j)e[i][j]=min(powM(A[i],A[j]),powM(A[j],A[i]));
  }
  int l=0,r=M;
  while(l<r-1){
    int m=l+r >>1;
    if(bfs(m))r=m;else l=m;
  }
  cout<<l;
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
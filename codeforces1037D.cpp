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
vector<vector<int>> a;
std::vector<int> bfs(int s) {
  std::vector<int> r;
  u[s]=1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    r.pb(v);q.pop();
    for (auto to : a[v]) {
      if (u[to] == 0) {
        u[to] = 1;
        q.push(to);
      }
    }
  }
  return r;
}
// void dfs(int x){
//     if(u[x])return;
//     u[x]=1;s++;
//     // if(st)c[x]=i+1;
//     for(int y:a[x])if(!u[y])
//         dfs(y);
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
int in[N];
bool cmp(int a,int b){
  return in[a]<in[b];
}
void solve(){
  int n;cin>>n;a=std::vector<std::vector<int>> (n);
  for (int i = 0; i < n-1; ++i)
  {
    int u,v;cin>>u>>v;
    u--,v--;a[u].pb(v),a[v].pb(u);
  }
  memset(in,0,n);std::vector<int> seq;
  for (int i = 0; i < n; ++i)
  {
    int x;cin>>x;seq.pb(x-1);
    in[x-1]=i;
  }
  for (int i = 0; i < n; ++i)
  {
    std::vector<int> g=a[i];
    sort(g.begin(), g.end(),cmp);
    a[i]=g;
  }
  std::vector<int> r=bfs(0);
  // for (auto i:r)
  // {
  //   cout<<i<<" ";
  // }
  if(seq==r)cout<<"Yes";else cout<<"No";
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
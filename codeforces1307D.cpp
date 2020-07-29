#include <bits/stdc++.h>
// #include <numeric>
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
// bool u[N];int s;
int A[N],B[N];int S[N];
vector<vector<int>> a;
void bfs(int s,int* d) {
  d[s] = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();q.pop();
    for (auto to : a[v]) {
      // cout<<d[to]<<" "<<to<<"\n";
      if (d[to] == 0) {
        d[to] = d[v] + 1;
        q.push(to);
      }
    }
  }
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
// struct b{int w,pos;}A[N];
bool cmp(int a, int b){
  return A[a]<A[b];
}
void solve(){
  int n,m,k;cin>>n>>m>>k;
  for (int i = 0; i < k; ++i)
  {
    cin>>S[i];
  }
  a=std::vector<std::vector<int> > (n+10);
  for (int i = 0; i < m; ++i)
  {
    int u,v;cin>>u>>v;
    a[u].pb(v),a[v].pb(u);
  }
  // memset(A,-1,sizeof(A));memset(B,-1,sizeof(B));
  bfs(1,A);
  bfs(n,B);
  // sort(S,S+k,cmp);
  // int dis=abs(A[S[0]]-A[S[1]]);
  sort(S,S+k,cmp);
  int ma=B[S[k-1]],ans=0;
  for(int i=k-2;i>-1;i--)ans=max(ans,ma+A[S[i]]),ma=max(ma,B[S[i]]);
  // cout<<S[0]<<S[1];
  // for (int i = 1; i <= n; ++i)
  // {
  //   cout<<A[i];
  // }
  // cout<<dis;
  cout<<min(ans,A[n])-1;
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
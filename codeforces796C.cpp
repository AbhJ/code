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
// bool u[N];int s;
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
int A[N];
void solve(){
  int n;cin>>n;
  multiset<int,greater<int> >s;
  for (int i = 1; i <=n ; ++i)
  {
    cin>>A[i];s.insert(A[i]+2);
  }
  a=vector<vector<int>>(n+10);
  for (int i = 0; i < n-1; ++i)
  {
    int u,v;cin>>u>>v;
    a[u].pb(v),a[v].pb(u);
  }
  int x=2e9;
  for(int i=1;i<=n;i++){
    s.erase(s.find(A[i]+2));
    s.insert(A[i]);//neighbouring
    for(auto j:a[i]){
      s.erase(s.find(A[j]+2));s.insert(A[j]+1);//semineighbouring
    }
    x=min(x,*s.begin());
    s.erase(s.find(A[i]));
    s.insert(A[i]+2);
    for(auto j:a[i]){
      s.erase(s.find(A[j]+1));s.insert(A[j]+2);
    }
  }
  cout<<x;
  // int x=0,y=0;
  // for(int i=1;i<=n;i++){
  //   if(A[i].w==ma)x++,X[x]=A[i].pos;
  //   if(A[i].w==ma-1)y++,Y[y]=A[i].pos;
  // }
  // if(x==1)


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
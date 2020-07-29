#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
vector<int>a[N];
int ans;
vector<int>V;
bool A[N],B[N];
void dfs(int u,int v=0,bool y=0,bool x=0){
  if(B[u]^x)x^=1,V.pb(u);
  for(int i:a[u])if(i!=v){
    dfs(i,u,x,y);
  }
}
void solve(){
  int n;cin>>n;
  for (int i = 0; i < n-1; ++i)
  {
    int x,y;cin>>x>>y;
    a[x].pb(y),a[y].pb(x);
  }
  for (int i = 1; i <= n; ++i)cin>>A[i];
  for (int i = 1; i <= n; ++i)cin>>B[i],B[i]^=A[i];
  // for (int i = 1; i <= n; ++i) cout<<B[i]; 
  dfs(1);
  cout<<V.size()<<"\n";
  for(auto i:V)cout<<i<<"\n";
  // cout<<ans;
}
int main()
{
    // ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<len;
      // cout<<"\n";
    // }
    return 0;
}
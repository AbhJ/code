#include <bits/stdc++.h>
// #include <xeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
// const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
set<int> a[N];set<int>s;
void dfs(int u){
  if(s.count(u))s.erase(u);
  for(auto i:a[u]){
    if(s.count(i))dfs(i);
  }
}
void solve(){
  int n,k;cin>>n>>k;
  for (int i = 0; i < k; ++i)
  {
    int x,y;cin>>x>>y;
    a[x].insert(y),a[y].insert(x);
  }
  for(int i=1;i<=n;i++)s.insert(i);
  int c=0;
  for(int i=1;i<=n;i++){
    if(s.count(i)){
      c++;dfs(i);
    }
  }
  cout<<k-n+c;
}
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    // }
    return 0;
}
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
vector<int> a[N];int x,y;set<int>s;
ll dfs(int u,int p=0){
  ll len=1;/*s.erase(u);*/
  for (auto i:a[u])if(i!=p)
  {
    // s.erase(i);
    len=max(len,dfs(i,u));
  }
  return len+1;
}
ll solve(){
  int n;cin>>n;
  for (int i = 1; i <=n; ++i)
  {
    a[i].clear();
  }
  for (int i = 0; i < n-1; ++i)
  {
    cin>>x>>y;a[x].pb(y),a[y].pb(x);
  }
  s.clear();
  for (int i = 1; i <= n; ++i)
  {
    if(a[i].size()==1)s.insert(i);
  }
  ll len=0;
  // for (int i =1; i <= n; ++i)s.insert(i);
  for (auto i:s){
    // if(s.count(i)){
      len=max(len,dfs(i));
    // }
  }
  // cout<<len-2;
  return len-2;/*0;*/
}
bool solvee(){
  int t;cin>>t;
  ll len=0;
  while(t--){
    len+=solve();
    // cout<<len;
    // cout<<"\n";
  }
  cout<<len;
  return 0;
}
int main()
{
    // ibs;cti;
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    while(solvee());
    return 0;
}
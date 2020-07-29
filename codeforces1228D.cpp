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
set<int>a[N];
void solve(){
  int n,m;cin>>n>>m;
  for (int i = 0; i < m; ++i)
  {
    int x,y;cin>>x>>y;a[x].insert(y),a[y].insert(x);
  }
  map<set<int>,int>M;
  int x=1;
  for (int i = 1; i <= n; ++i)
  {
    if(a[i].size()==0){cout<<-1;return;}
    if(M.count(a[i])==0)M[a[i]]=x,x++;
  }
  if(x!=4){cout<<-1;return;}
  for(int i = 1; i <= n; ++i)cout<<M[a[i]]<<" ";
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
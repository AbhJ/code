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
void solve(){
  int n,M;cin>>n>>M;
  std::map<int, int> m;queue<int>q;
  for (int i = 0; i < n; ++i)
  {
    int x;cin>>x;m[x]=0,q.push(x);
  }
  vector<int> v;
  ll ans=0;
  while(!q.empty() and v.size()!=M){
    int x=q.front();q.pop();
    if(m[x]){
      v.pb(x);ans+=m[x];
    }
    if(!m.count(x-1)){
      q.push(x-1);m[x-1]=1+m[x];
    }
    if(!m.count(x+1)){
      q.push(x+1);m[x+1]=1+m[x];
    }
  }
  cout<<ans<<"\n";
  for(auto i:v)cout<<i<<" ";
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
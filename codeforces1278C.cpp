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
void solve(){
  int n;cin>>n;std::vector<int> v(2*n);
  for(int i=0;i<2*n;i++)cin>>v[i];
  std::map<int, int> d;
  d[0]=n;int x=0;
  for (int i = 2*n-1; i >=n ; --i)
  {
    if(v[i]==1)x--;
    else x++;
    d[x]=i-n;
  }
  x=0;int ans=n+d[0];
  for (int i = 0; i < n; ++i)
  {
    if(v[i]==1)x++;else x--;
    if(d.count(x))ans=min(ans,n-i-1+d[x]);
  }
  cout<<ans;
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
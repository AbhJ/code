#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e3+10;
const ll M = 998244353; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  string s;cin>>s;
  ll area=0,l=0,r=0,u=0,d=0,x=0,y=0,
  MAx=0,MIx=0,MAy=0,MIy=0;
  for (auto i:s)
  {
    if(i=='W')y++,u=max(u,y);
    if(i=='A')x--,l=min(x,l);
    if(i=='S')y--,d=min(d,y);
    if(i=='D')x++,r=max(x,r);
    MAx=max(MAx,r-x),MAy=max(MAy,u-y),
    MIy=max(MIy,y-d),MIx=max(MIx,x-l);
  }
  x=r-l+1,y=u-d+1;
  area=x*y;//intial area
  if(x>2 and MAx!=MIx)area=min(area,x*y-y);
  if(y>2 and MIy!=MAy)area=min(area,x*y-x);
  cout<<area;
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
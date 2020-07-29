#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e4+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int a[N],l[N],r[N];bool b[N];
void solve(){
  ll n,p,w,d;cin>>n>>p>>w>>d;ll y=0,x=-1,z=-1;
  for (y=0;y<w;y++)
  {
    if(p-y*d<0)continue;
    if((p-y*d)%w)continue;
    if((p-y*d)/w+y>n)continue;
    x=p-y*d;x/=w;
    z=n-x-y;
    break;
  }
  if(x+1)
  cout<<x<<" "<<y<<" "<<z;
  else cout<<-1;
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
#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const ll M =  998244353; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll n,Sx;
pair<int,int>v[N];
bool f(int x){
  ll c=0,s=0;
  for (int i = n-1; i>-1 ; --i)
  {
    if((v[i].S>=x)  and (c<=n/2))c++,s+=max(x,v[i].F);
    else s+=v[i].F;
  }
  return (s<=Sx)&&(c>n/2);
}
void solve(){
  cin>>n>>Sx;
  for (int i = 0; i < n; ++i)
  {
    cin>>v[i].F>>v[i].S;
  }
  sort(v,v+n);
  int l=0,r=1e9,mid,ans;
  while(l<=r){
    mid=l+r;mid=mid>>1;
    if(f(mid))ans=mid,l=mid+1;
    else r=mid-1;
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
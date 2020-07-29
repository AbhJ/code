#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e6+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void solve(){
  ll n;cin>>n;std::vector<ll> a,b;ll W=0;
  for (int i = 0; i < n; ++i)
  {
    ll w,c;cin>>w>>c;W+=w;
    if(w==1)a.pb(c);else b.pb(c);
  }
  sort(a.begin(), a.end());sort(b.begin(),b.end());
  ll ans[W+1],i=a.size()-1,j=b.size()-1;
  ans[0]=0;
  if(i>=0)ans[1]=a[i];else ans[1]=0;
  i--;
  for (ll w = 1; w < W; ++w)
  {
    ll c1=ans[w],c0=ans[w-1];
    if(i>=0)c1+=a[i];if(j>=0)c0+=b[j];
    ans[w+1]=max(c1,c0);
    if(c1>=c0)i--;else i++,j--;
  }
  for (ll w = 1; w <= W; ++w)
  {
    cout<<ans[w]<<" ";
  }
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
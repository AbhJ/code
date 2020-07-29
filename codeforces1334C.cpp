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
  int n;cin>>n;std::vector<ll> a(n),b(n),v(n+1);
  ll mi=1e18,ans=0;
  for (int i = 0; i < n; ++i)
  {
    cin>>a[i]>>b[i];
    // mi=min(1LL*a[i],mi);
    if(i)v[i]=a[i]-b[i-1];
  }
  v[0]=a[0]-b[n-1];
  for (int i = 0; i < n; ++i)
  {
    if(v[i]>0)ans+=v[i],mi=min(mi,b[(i+n-1)%n]);
    else mi=min(mi,a[i]);
  }
  cout<<ans+mi;
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
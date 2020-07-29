#include <bits/stdc++.h>
// #include <numeric>
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
ll f[N];bool p[N];
void calc(){
  memset(p,1,sizeof(p));
  p[0]=p[1]=0;
  for (ll i = 4; i <= 10000; i += 2) {
      p[i] = 0;
  }
  for (ll i = 9; i <= 10000; i += 6) {
      p[i] = 0;
  }
  for (ll i = 5; i * i <= 10000; i += 6) {
      if (p[i]) {
          for (ll j = i * i; j <= 10000; j += 2 * i) {
              p[j] = 0;
          }
      }
      if (p[i + 2]) {
          for (ll j = (i + 2) * (i + 2); j <= 10000; j += (2 * (i + 2))) {
              p[j] = 0;
          }
      }
  }
}
void solve(){
  ll l,r;cin>>l>>r;
  memset(f,0,sizeof(f));
  for (ll i = 1; i <= sqrt(r); ++i)
  {
    for(ll j=((l-1)/i+1)*i;j<=r;j+=i)//all multiples of i from l to r
    {
      if(j==i*i)f[j-l]++;
      else if(j>i*i)f[j-l]+=2;
    }
  }
  ll ans=0;
  for(ll i=0;i<=r-l;i++){
    if(p[f[i]])ans++;
  }
  cout<<ans;
}
int main()
{
    ibs;cti;
    calc();
    int t;cin>>t;
    while(t--){
      solve();
      cout<<"\n";
    }
    return 0;
}
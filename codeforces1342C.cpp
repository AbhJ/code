#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const ll M = 998244353 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll lcm(ll a, ll b)  
{  
  return (a*b)/__gcd(a, b);  
}  
int p[N];ll l,r;
void solve(){
  ll a,b,q;cin>>a>>b>>q;
  ll L=lcm(a,b);
  for (ll i = 0; i < L; ++i)
  {
    p[i+1]=p[i];
    if((i%a)%b!=(i%b)%a)p[i+1]++;
  }
  while(q--){
    cin>>l>>r;r++;
    cout<<(r/L-l/L)*p[L]-p[l%L]+p[r%L]<<" ";
  }
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    }
    return 0;
}
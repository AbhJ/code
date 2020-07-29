#include <bits/stdc++.h>
#include <numeric> 
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
const ll M = 998244353; // modulo
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
long long C(long long n,long long r)
{
    long long N=1,R=1;
    for(long long i=1;i<=n;i++) N=N*i%M;
    for(long long i=1;i<=r;i++) R=R*i%M;
    for(long long i=1;i<=n-r;i++) R=R*i%M;
    return (N*powM(R,M-2))%M;
}
void solve(){
    ll n,m;cin>>n>>m;
    if(n==2){cout<<0;return;}
    ll x=1;x=powM(2,n-3);
    x=(x*(n-2))%M;x=(x*C(m,n-1)%M)%M;
    cout<<x;    
}
int main()
{   
    ibs;cti;
    solve(),cout<<"\n";
    return 0;
}
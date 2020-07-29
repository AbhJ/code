#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
const long M = 1000000007; // modulo
// int m[2][N];//the grid
ll c(ll n, ll k) {
   ll C[k+1];
   memset(C, 0, sizeof(C));
   C[0] = 1;
   for (ll i = 1; i <= n; i++) {
      for (ll j = min(i, k); j > 0; j--)
         C[j] = C[j] + C[j-1];
   }
   return C[k];
}
int main()
{   
    ibs;cti;
    ll n;cin>>n;std::vector<ll> v(n+10),d[N];
    ll a,ans=0;
    for (int i = 1; i < n+1; ++i)
    {
      cin>>a;a=min(a,n);
      for (int j = a; j > 0 ; j-=j&-j)ans+=v[j];//weight of lowest non zero in binary of x
      if(a>i){
        for(int x=i;x<=n;x+=x&-x)v[x]++;
        d[a].pb(i);
      }
      for(int x: d[i])
        for(int x1=x;x1<=n;x1+=x1&-x1)v[x1]--;
    }
    cout<<ans;  
    return 0;
}
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
ll lis[1005];
ll l(int n){
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i)
    cin>>v[i];
  for (int i = 0; i < 1005; ++i)
    lis[i]=1;
  ll m=0;
  for (int i = 1; i < n; ++i)
  {
    for(int j=0;j<i;j++){
      if(v[i]>v[j])
        lis[i]=max(lis[i],1+lis[j]);
    }
    m=max(m,lis[i]);
  }
  return m;
}
int main()
{   
    ibs;cti;int t;cin>>t;while(t--){
    int n;cin>>n;
    cout<<l(n)<<"\n";
    }
    return 0;
}
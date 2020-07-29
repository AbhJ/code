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
// ll result[N];
// ll fact(ll n) {
//       result[0] = 1;
//       for (ll i = 1; i <= n; ++i) {
//          result[i] = (i * result[i - 1])%M;
//       }
//       return result[n];
// }
int main()
{   
    ibs;cti;int t;cin>>t;while(t--){
      int n;cin>>n;
      string s;cin>>s;std::vector<char> v;
      for (int i = 0; i < n; ++i)
      {
        if((s[i]-'0')%2)v.pb(s[i]);
        if(v.size()==2)break;
      }
      if(v.size()<2){cout<<"-1\n";continue;}
      cout<<v[0]<<v[1]<<"\n";
    }
    return 0;
}
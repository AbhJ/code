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
      std::vector<int> v(n);int ma=INT_MIN,mi=INT_MAX,mini,maxi;
      for (int i = 0; i < n; ++i){
        cin>>v[i];if(v[i]<mi)mini=i;if(v[i]>ma)maxi=i;mi=min(v[i],mi),ma=max(ma,v[i]);
      }
      bool c=0;
      for (int i = 1; i < n-1; ++i)
      {
        if(v[i]>v[i-1] and v[i]>v[i+1])c=1;
      }
      if(n==1)c=1;
      if(n==2 and!(!v[0] and !v[1])){cout<<"Yes\n";continue;}
      if((n==2) and !c){cout<<"No\n";continue;}
      // cout<<mi<<ma;
      bool check=0;
      // for (int i = 0; i <= maxi-1; ++i)
      // {
      //   if(ma-v[i]>maxi-i){check=1;break;}
      // }
      // for (int i = maxi+1; i < n; ++i)
      // {
      //   if(ma-v[i]>i-maxi){check=1;break;}
      // }
      // if(check or mi>=ma-1)cout<<"No\n";else cout<<"Yes\n";
      if(v[n/2]==v[n/2-1] and !(n%2) and v[n/2]<n/2)check=1;
      for (int i = 0; i < n; ++i)
      {
        if(v[i]<min(i,n-i-1)){check=1;break;}
        // if(i==n/2 and v[i]==v[i+1] and v[i]==i)check=1;
      }
      // cout<<"Yes\n";
      cout<<(!check?"Yes":"No")<<"\n";
    }
    return 0;
}
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
ll v[1005][1005];
ll f(string a, string b, int n, int m){
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= m; ++j)
    {
      if(a[i-1]==b[j-1])
        v[i][j]=1+v[i-1][j-1];
      else v[i][j]=max(v[i-1][j],v[i][j-1]);
    }
  }
  return v[n][m];
  // if(n==0 or m==0)return 0;
  // if(v[n][m])return v[n][m];
  // if(a[n-1]==b[m-1]){v[n][m]=1+v[n-1][m-1];return v[n][m]=1 + f(a,b,n-1,m-1);}
  // // v[n][m]=max(v[n-1][m],v[n][m-1]);
  // return v[n][m]=max(f(a,b,n-1,m),f(a,b,n,m-1));
}
int main()
{   
    ibs;cti;int t;cin>>t;while(t--){
    string a,b;int x,y;cin>>x>>y;
    cin>>a>>b;
    for (int i = 0; i <1005; ++i)
    {
      for (int i1 = 0; i1 < 1005; ++i1)
      {
        v[i][i1]=0;
      }
    }
    cout<<f(a,b,x,y)<<"\n";
    }
    return 0;
}
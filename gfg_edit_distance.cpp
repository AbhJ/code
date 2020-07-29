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
ll e[1005][1005];
ll ed(string a, string b){
  int n=a.length(),m=b.length();
  for (int i = 0; i <= n; ++i)
  {
    for (int j = 0; j <= m; ++j)
    {
      if(!i)e[i][j]=j;
      else if(!j)e[i][j]=i;
      else if(a[i-1]==b[j-1])e[i][j]=e[i-1][j-1];
      else e[i][j]=1+min(e[i-1][j],min(e[i][j-1],e[i-1][j-1]));
    }
  }
  return e[n][m];
}
int main()
{   
    ibs;cti;int t;cin>>t;while(t--){
    int n,m;cin>>n>>m;string a;string b;cin>>a>>b;
    cout<<ed(a,b)<<"\n";
    }
    return 0;
}
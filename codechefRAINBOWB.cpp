#include <bits/stdc++.h>
#include <numeric>
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
ll f[N][8];
void solve(){
  int n,k;cin>>n;
  n=n+1;n=n>>1;
  f[0][0]=1;
  for (int i = 1; i <= n; ++i)
  {
    if(i<=7)k=i;else k=7;
    for (int j = 1; j <= k; ++j)
    {
      f[i][j]=((f[i][j]+f[i-1][j-1])%M+f[i-1][j])%M;
    }
  }
  cout<<f[n][7];
}
int main()
{   
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}
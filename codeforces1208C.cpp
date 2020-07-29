#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e3+10;
const ll M = 998244353 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int a[N][N];
void solve(){
  int n;cin>>n;
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      int I=i%(n/2),J=j%(n/2);
      a[i][j]=4*(I*(n/2)+J);
      if(j>n/2 and i<=n/2)a[i][j]++;
      if(i>n/2 and j>n/2)a[i][j]+=3;
      if(i>n/2 and j<=n/2)a[i][j]+=2;
    }
  }
  for (int i = 1; i <= n; ++i)
  {
    int x=0;
    for (int j = 1; j <= n; ++j)
    {
      cout<<setw(10)<<a[i][j]<<" ";
    }
    cout<<"\n";
  }
}
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    // }
    return 0;
}
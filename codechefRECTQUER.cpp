#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e2+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int a[N][N],dp[11][N][N];
void solve(){
  int n;cin>>n;
  for (int i = 1; i <= n; ++i)
    for(int j=1;j<=n;j++)
      cin>>a[i][j];
  int q;cin>>q;
  for(int k=1;k<=10;k++)
    for (int i = 1; i <= n; ++i)
        for(int j=1;j<=n;j++)
          dp[k][i][j]=dp[k][i][j-1]+(a[i][j]==k);
  while(q--){
    int ans=0;int x,y,X,Y;cin>>x>>y>>X>>Y;
    for(int k=1;k<=10;k++)
      for (int i = x; i <= X; ++i)
        if(dp[k][i][y-1]!=dp[k][i][Y]){
          ans++;break;
        }
    cout<<ans<<"\n";
  }
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
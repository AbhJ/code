#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const ll M = 1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll n,x[2][N],y[2][N],c[N],a[N],b[N];//0 from up 1 from down
//dynamically find min cost of path
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)cin>>b[i];
  // dp[0][n]=dp[1][n]=c[n]=a[n]+b[n];
  ll t=0;
  for(int i=n;i>=1;i--,t+=2){
    c[i]=c[i+1]+a[i]+b[i];
    x[0][i]=x[0][i+1]+c[i+1]+(t+1)*b[i];
    x[1][i]=b[i]+max(y[0][i+1],y[1][i+1])+2*c[i+1];
    y[1][i]=y[1][i+1]+c[i+1]+(t+1)*a[i];
    y[0][i]=a[i]+max(x[0][i+1],x[1][i+1])+2*c[i+1];
  }
  cout<<max(x[0][1],x[1][1]);
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
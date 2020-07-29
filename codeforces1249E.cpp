#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const ll M =  998244353; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
int a[N],b[N],dp[N+1][2];
void solve(){
  int n,c;cin>>n>>c;
  for (int i = 0; i < n-1; ++i)
  {
    cin>>a[i];
  }
  for (int i = 0; i < n-1; ++i)
  {
    cin>>b[i];
  }
  //dp[i][0] is time for stair till i
  //dp[i][1] is time for  lift till i
  dp[0][0]=0;dp[0][1]=c;
  cout<<0<<" ";
  for (int i = 1; i < n; ++i)
  {
    dp[i][0]=a[i-1]+min(dp[i-1][0],dp[i-1][1]);
    dp[i][1]=b[i-1]+c+min(dp[i-1][0],dp[i-1][1]-c);
    cout<<min(dp[i][0],dp[i][1])<<" ";
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
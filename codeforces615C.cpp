#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e3+110;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll dp[N][N][2];
void solve(string s,string t,int k){
  int n,m;n=s.length(),m=t.length();
  for(int i=m-1;i>-1;i--){
    for(int j=n-1;j>-1;j--){
      if(t[i]==s[j])
        dp[i][j][k]=dp[i+1][j+1][k]+1;
      // cout<<dp[i][j][k]<<" ";
    }
    // cout<<"\n";
  }
}
int main()
{
    ibs;cti;
    string s,t;
    cin>>s>>t;
    int n,m;n=s.length(),m=t.length();
    // int t;cin>>t;
    // while(t--){
      solve(s,t,0);/*cout<<"\n\n";*/
      reverse(s.begin(), s.end());
      solve(s,t,1);
      // cout<<"\n";
    // }
    std::vector<pair<int,int>> v;
    for(int i=0;i<m;){
      ll ma=0,l=-1,r=-1;
      for(int j=0;j<n;j++){
        if(dp[i][j][0]>ma)ma=dp[i][j][0],r=j+ma,l=j+1;
      }
      for(int j=0;j<n;j++){
        if(dp[i][j][1]>ma)ma=dp[i][j][1],l=n-j,r=n+1-j-ma;
      }
      i+=ma;
      if(!ma){cout<<"-1";return 0;}
      v.pb({l,r});
    }
    cout<<v.size()<<"\n";
    for(auto i:v)cout<<i.F<<" "<<i.S<<"\n";
    return 0;
}

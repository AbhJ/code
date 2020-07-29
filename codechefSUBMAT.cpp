#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <numeric>
#include <vector>
#include <iterator> 
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
// #include <bits/stdc++.h>
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int a[N][N],dp[N][N],ans=0;int k1[N],k2[N];stack<int>s;
void solve(){
    int n,m;cin>>n>>m;ans=0;
     for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        cin>>a[i][j];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++)
        if(a[i][j]==0)dp[i][j]=i;
        else dp[i][j]=dp[i-1][j];
    }
    // for(int i=1;i<=n;i++){
    //   for(int j=1;j<=m;j++)cout<<dp[i][j]<<" ";cout<<"\n";
    // }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        while(s.empty()==0 and dp[i][s.top()]<=dp[i][j])
          s.pop();//these are not the possible left boundaries
        if(s.empty()==0)k1[j]=s.top();else k1[j]=1;
        s.push(j);
      }
      while(s.empty()==0)s.pop();
      for(int j=m;j>=1;j--){
        while(s.empty()==0 and dp[i][s.top()]<=dp[i][j])
          s.pop();//these are not the possible right boundaries
        if(s.empty()==0)k2[j]=s.top();else k2[j]=m;
        s.push(j);
      }
      while(s.empty()==0)s.pop();
      // for(int j=1;j<=m;j++)cout<<k1[j]<<" ";
      //   cout<<"\n";
      for(int j=m;j>=1;j--)ans=max(ans,min((i-dp[i][j]),(k2[j]-k1[j]-1)));
    }
    cout<<ans;
}
int32_t main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;
  while(t--){solve();cout<<"\n";}
  return 0;
}
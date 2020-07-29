//Coded by Abhijay Mitra
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
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
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
#define res(vector) v.resize(unique(v.begin(), v.end()) - v.begin());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using namespace std;
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,a[N][N],ans;
void solve(){
  cin>>n>>m;ans=inf;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>a[i][j];
  for(int x=0;x<n;x++)
    for(int y=0;y<m;y++){
      //we assume this element to be unchanged
      vector<vector<int>>dp(n);
      for(int i=0;i<n;i++)dp[i]=vector<int>(m,inf);
      int X=a[x][y]-x-y;
      if(a[0][0]<X)continue;
      dp[0][0]=a[0][0]-X;
      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
          if(a[i][j]>=X+i+j){
            if(i>0 and j>0)dp[i][j]=min(dp[i-1][j]+a[i][j]-(X+i+j),(dp[i][j-1]+a[i][j]-(X+i+j)));
            else if(i>0)dp[i][j]=dp[i-1][j]+a[i][j]-(X+i+j);
            else if(j>0)dp[i][j]=dp[i][j-1]+a[i][j]-(X+i+j);
          }
        }
      /*if(dp[n-1][m-1])*/ans=min(ans,dp[n-1][m-1]);
      // cout<<dp[n-1][m-1];
    }
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
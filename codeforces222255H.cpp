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
const int N=1e3+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int dp[N][N*10],b,x,a[N],cost[N];
int n,w;
void solve(){
  cin>>n>>w>>b>>x;memset(dp,-1,sizeof(dp));
  int birds=0;
  for(int i=0;i<n;i++)cin>>a[i],birds+=a[i];
  for(int i=0;i<n;i++)cin>>cost[i];
  dp[0][0]=w;
  //dp[i][j] is defined as the money required to buy j birds from upto ith tree
  for(int i=1;i<=n;i++){
    for(int j=0;j<=birds;j++){
        //we buy k birds from ith tree
        for(int k=0;k<=min(birds,a[i-1]);k++){
            if(j<k)break;
            if(dp[i-1][j-k]==-1)continue;
            //I can't have more money than capacity
            int money_left=min(dp[i-1][j-k]+x,w+(j-k)*b);
            if(money_left<k*cost[i-1])continue;
            //I can't have more money than capacity
            dp[i][j]=max(dp[i][j],min(money_left-k*cost[i-1],w+(j-k)*b));
        }
    }
  }
  for(int i=birds;i>=0;i--)
    if(dp[n][i]!=-1){
        cout<<i;return;
    }
}
int32_t main()
{
  // ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // int x=0;
  // while(t--){solve();cout<<"\n";}
  return 0;
}
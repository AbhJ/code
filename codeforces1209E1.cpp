#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <numeric>
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
// #define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e2+10;
const int inf = /*0x3f3f3f3f*/1e9;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,m,ans,b[N];vector<vector<int>>a;
void calc(){
  int x=0;
  for(int i=1;i<=n;i++)b[i]=0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      b[i]=max(b[i],a[j][i]);
  for(int i=1;i<=n;i++)
    x+=b[i];
  ans=max(ans,x);
}
void f(int k=1){
  if(k==m+1){calc();return;}
  for(int num=1;num<=n;num++){
      int last=a[k][n];
      for(int i=n;i>=2;i--){
        a[k][i]=a[k][i-1];
      }
      a[k][1]=last;
      //one rotation completed
      f(k+1);
  }
}
bool cmp(vector<int>arr,vector<int>brr){
  return arr[1]>brr[1];
}
void solve(){
  cin>>n>>m;
  ans=0;
  a=vector<vector<int>>(m+1);
  for(int i=0;i<=m;i++)a[i]=vector<int>(n+1,0);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>a[j][i];
  //***********if you want brute force solution comment from here
  for(int j=1;j<=m;j++){
    //we basically set up all the column maximas to the first row
    int ma=-inf;
    for(int i=1;i<=n;i++)
      ma=max(ma,a[j][i]);
    while(a[j][1]!=ma){
      int last=a[j][n];
      for(int i=n;i>=2;i--){
        a[j][i]=a[j][i-1];
      }
      a[j][1]=last;
    }
  }
  //by sorting the arrays columnwise we ensure that the largest m
  //elements get a chance to move to other rows becoming the
  //largest elements in those rows which anyhow would be in the
  //optimal solution
  sort(a.begin()+1, a.end(),cmp);
  m=min(n,m);
  //*************to here. Code works just fine but TLE.
  f();
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  int x=0;
  int t;cin>>t;while(t--){/*x++;cout<<"Case #"<<x<<": ";*/solve();cout<<"\n";}
  return 0;
}
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
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/ 1e18+12;
// const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int a[N],b[N],i;bool vis[N][7],ok;
void dfs(int n,int lf){
  if(ok==1)return;
  if(a[n]==0){
    for(int i=1;i<n;i++)
    cout<<b[i]<<" ";
    ok=1;
  }
  if(vis[n][lf]==1)return;
  vis[n][lf]=1;
  int c=0;
  for (int f = 5; f >0; --f)
  {
    if(a[n]<a[n-1] and f<lf)
      b[n]=f,dfs(n+1,f),c;
    if(a[n]>a[n-1] and f>lf)
      b[n]=f,dfs(n+1,f),c;
    if(a[n]==a[n-1] and f!=lf)
      b[n]=f,dfs(n+1,f),c;
  }
}
int n;
void solve(){
  cin>>n;int num=1;for(int i=1;i<=n;i++)cin>>a[i];
  // a[0]=inf;
  dfs(1,0);
  if(ok==0)cout<<-1;
}
int32_t main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}
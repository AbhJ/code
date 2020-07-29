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
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,q,x,y,f[N][30],ans[N],pre[N],a[N],p[N],last_seen[N];
void solve(){
  cin>>n>>m>>q;
  for(int i=1;i<=n;i++)cin>>p[i];
  for(int i=1;i<=m;i++)cin>>a[i];
  for(int i=2;i<=n;i++)pre[p[i]]=p[i-1];
  pre[p[1]]=p[n];
  //pre[i] is the pre element to i in the permutation p
  for(int i=1;i<=m;i++){
    f[i][0]=last_seen[pre[a[i]]];
    for(int j=1;j<=30;j++)
      f[i][j]=f[f[i][j-1]][j-1];
    int x=i;
    for(int j=30;j>=0;j--)
      if((n-1) & (1<<j))
        x=f[x][j];
    //we try to find the rightmost position left of i such that there subsequence till i
    //which is a shift of p
    if(x)ans[i]=x;
    last_seen[a[i]]=i;
  }
  for(int i=1;i<=m;i++)ans[i]=max(ans[i],ans[i-1]);
  for(int i=1;i<=q;i++){
    cin>>x>>y;
    if(ans[y]>=x)cout<<1;
    else cout<<0;
  }
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();/*cout<<"\n";*/}
  return 0;
}
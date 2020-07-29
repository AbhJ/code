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
const double Pi = acos(-1);
#define F first
#define S second
int x[N],y[N],r[N],n,p[N],P[N];vector<int>a[N];double ans;
bool inside(int u,int v){
   return ((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v])<=(r[u]-r[v])*(r[u]-r[v]));
}
void dfs(int u,bool parity){
  P[u]=parity;
  parity^=1;
  for(auto i:a[u])
    dfs(i,parity);
}
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++)cin>>x[i]>>y[i]>>r[i];
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
      if((p[i]==0 or r[j]<r[p[i]]) and inside(i,j)==1 and r[j]>r[i]){
        p[i]=j;
    }
    a[p[i]].pb(i);
  }
  //for all disjoint trees we call dfs
  for(int i=1;i<=n;i++)if(p[i]==0)dfs(i,0);
  //we greedily chose all the initial white circles for night
  //rest original remains however they are
  //and greedily we only take the odd depth circles
  for(int i=1;i<=n;i++){
    double area=Pi*r[i]*r[i];
    if(p[i]==0 or P[i]==1)ans+=area;
    else ans-=area;
  }
  cout<<setprecision(20)<<ans;
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
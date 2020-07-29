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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,A[N],x,dist[N],r;vector<int>a[N];stack<int>odd;
void dfs(int u,int p=0){
  for(auto i:a[u])if(i!=p){
    dfs(i,u);
  }
  if((a[u].size()-dist[u])&1)odd.push(u);else cout<<u<<"\n",dist[p]++;
}
void solve(){
  cin>>n;if((n&1)==0)cout<<"NO";
  for(int i=1;i<=n;i++){
  cin>>x;if(x)a[i].pb(x),a[x].pb(i);else r=i;}
  if(n&1)
  cout<<"YES\n",
  dfs(r);
  while(odd.empty()==0)cout<<odd.top()<<"\n",odd.pop();
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
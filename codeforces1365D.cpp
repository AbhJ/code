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
#define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
#define cnt_res(v) std::distance(v.begin(),std::unique(v.begin(), v.end())); 
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using namespace std;
const int N=50+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int n,m;string s[N];int vis[N][N],visi[N][N],val[N][N];
int dfs(int x,int y){
  if(x==n-1 and y==m-1)return 1;
  if(x<0 or x>n-1 or y<0 or y>m-1)return 0;
  if(vis[x][y])return val[x][y];
  if(s[x][y]=='#')return 0;
  vis[x][y]=1;int va=0;
  for(int i=0;i<4;i++){
    va|=dfs(x+dx[i],y+dy[i]);
  }
  return val[x][y]=va;
}
void solve(){
  cin>>n>>m;memset(vis,0,sizeof vis);memset(val,0,sizeof val);
  for(int i=0;i<n;i++)cin>>s[i];
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(s[i][j]=='B'){
        for(int k=0;k<4;k++){
          if(i+dx[k]>-1 and i+dx[k]<n and j+dy[k]<m and j+dy[k]>-1 and s[i+dx[k]][j+dy[k]]=='.')s[i+dx[k]][j+dy[k]]='#';
          if(i+dx[k]>-1 and i+dx[k]<n and j+dy[k]<m and j+dy[k]>-1 and s[i+dx[k]][j+dy[k]]=='G'){cout<<"No";return;}
        }
      }
  memset(vis,0,sizeof vis);memset(val,0,sizeof val);
  for(int k=0;k<4;k++)
    dfs(n-1-dx[k],m-1-dy[k]);
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(s[i][j]=='G'){
        if(vis[i][j]==0 or s[n-1][m-1]=='#'){cout<<"No";return;}
      }
  cout<<"Yes";
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
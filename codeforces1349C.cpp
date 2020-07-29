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
const int N=1e3+10;
const int inf = /*0x3f3f3f3f*/1e9+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int n,m,t,x,y,p;string s[N];
// vector<vector<int>>vis;
int vis[N][N];
int c[N][N],d[N][N];
void f(){
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      for(int k=0;k<4;k++)
        if(s[i+dx[k]][j+dy[k]]==s[i][j])c[i][j]=1;
}
void g(){
  queue<pair<int,int>>q;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(c[i][j]==1)vis[i][j]=1,q.push({i,j});
  while(q.empty()==0){
    int x=q.front().F,y=q.front().S;q.pop();
    for(int i=0;i<=3;i++){
      int X=x+dx[i],Y=y+dy[i];
      if(X<1 or X>n or Y<1 or Y>m or vis[X][Y]==1)continue;
      d[X][Y]=d[x][y]+1;
      vis[X][Y]=1;
      q.push({X,Y});
    }
  }
}
void solve(){
  cin>>n>>m>>t;
  //colour changes only if it has adjacent element of same colour
  //non colour changers start changing colour once their neighbour become
  //colour changers
  //eg. 101
  //    110
  //    010
  // a[1][2] changes colour only after 2nd iteration
  //for every cell we find nearest colour changer. It takes that many
  //iteration to become colour changer
  for(int i=1;i<=m+2;i++)s[0]+='#',s[n+1]+='#';
  for(int i=1;i<=n;i++)cin>>s[i],s[i]='#'+s[i]+'#';
  //let's identify colour changers
  f();
  //let's find nearest colour changer
  g();
  while(t--){
    cin>>x>>y>>p;
    if(vis[x][y]==1)
    cout<<((s[x][y]-'0')^((max(0LL,p-d[x][y])&1)))<<"\n";
    else cout<<s[x][y]<<"\n";
  }
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
}
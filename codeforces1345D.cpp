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
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e3+10;
const int inf = /*0x3f3f3f3f*/1e9+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
string s[N];int n,m;set<int>awr,awc;set<pair<int,int>>S;
pair<int,int> parent[N][N];int ind[N][N];
pair<int,int> find_set(int x,int y) {
    if (make_pair(x,y) == parent[x][y])
        return {x,y};
    return parent[x][y] = find_set(parent[x][y].F,parent[x][y].S);
}
void make_set(int x,int y) {
    parent[x][y] = {x,y};
    ind[x][y] = rand();
}
void union_sets(pair<int,int> a, pair<int,int> b) {
    a = find_set(a.F,a.S);
    b = find_set(b.F,b.S);
    if (a != b) {
        if (ind[a.F][a.S] < ind[b.F][b.S])
            swap(a, b);
        parent[b.F][b.S] = a;
    }
}
void solve(){
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>s[i],s[i]='@'+s[i];
  for(int i=1;i<=n;i++){
    int x=0;
    for(int j=1;j<=m;j++)
      if(s[i][j]=='#')x=1;
    if(x==0)awr.insert(i);
  }
  for(int j=1;j<=m;j++){
    int x=0;
    for(int i=1;i<=n;i++)
      if(s[i][j]=='#')x=1;
    if(x==0)awc.insert(j);
  }
  if(awc.size()!=0 and awr.size()==0){cout<<-1;exit(0);};
  if(awc.size()==0 and awr.size()!=0){cout<<-1;exit(0);};
  for(int i=1;i<=n;i++){
    if(awr.count(i)==1)continue;
    int x=0,num=0;
    for(int j=1;j<=m;j++){
      if(s[i][j]=='.')x=0;
      if(s[i][j]=='#' and x==1)continue;
      else if(s[i][j]=='#')x=1,num++;
    }
    if(num>1){cout<<-1;exit(0);};
  }
  for(int j=1;j<=m;j++){
    if(awc.count(j)==1)continue;
    int x=0,num=0;
    for(int i=1;i<=n;i++){
      if(s[i][j]=='.')x=0;
      if(s[i][j]=='#' and x==1)continue;
      else if(s[i][j]=='#')x=1,num++;
    }
    if(num>1){cout<<-1;exit(0);};
  }
   for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      make_set(i,j);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(s[i][j]=='.')continue;
      if(j!=m)if(s[i][j+1]=='#')union_sets({i,j},{i,j+1});
      if(i!=n)if(s[i+1][j]=='#')union_sets({i,j},{i+1,j});
    }
  }
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(s[i][j]=='#')S.insert(find_set(i,j));
  cout<<S.size();
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
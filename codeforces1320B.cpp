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
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int t;
set<int>a[N],b[N],lev[N];int p[N];int d[N];bool vis[N];
void bfs(int s){
    queue<int> q;
    q.push(s);
    vis[s]=1;
    d[s]=0;
    while(!q.empty()){
        int c = q.front();
        q.pop();
        for(auto x:a[c]){
            if(vis[x]==0){
                q.push(x);
                vis[x] = 1;
                d[x] = d[c] + 1;
            }
        }
    }
}
void solve(){
  int n,m;cin>>n>>m;
  memset(d,inf,sizeof(d));
  for (int i = 0; i < m; ++i)
  {
    int x,y;cin>>x>>y;
    a[y].insert(x);
    b[x].insert(y);
  }
  int k;cin>>k;
  int mi=0,ma=0;
  for (int i = 1; i <= k; ++i)cin>>p[i];
  bfs(t=p[k]);
  for (int i = 2;i<=k; ++i)
  {
    // bool A=0,b=0;
    if(d[p[i]]==d[p[i-1]]-1)
      for(auto w:b[p[i-1]]){
      if(w!=p[i] and d[w]==d[p[i]]){ma+=1;break;}
      }
    else if(d[p[i]]>=d[p[i-1]]){ma+=1,mi+=1;}
    // if(A==1)mi++;if(b==1)ma++;
  }
  cout<<mi<<" "<<ma;
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}
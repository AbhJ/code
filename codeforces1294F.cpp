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
// #define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
#define res(vector) v.resize(unique(v.begin(), v.end()) - v.begin());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using namespace std;
const int N=2e5+10;
// const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int dia,n,P[N],x,y,c,dc;vector<int>vis,dist;pair<int,int>D;vector<vector<int>>a;queue<int>d;
pair<int, int> bfs(int root){
    dist=vector<int> (n+1, 0);
    dist[root] = 1;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int curr = q.front();
        for(auto it : a[curr]){
            if(dist[it] != 0){
                continue;
            }
            q.push(it);
            dist[it] = dist[curr] + 1;
        }
        q.pop();
    }
    int mx = INT_MIN, vertex = -1;
    for(int i=1 ; i<=n ; i++){
        if(mx < dist[i]){
            mx = dist[i];
            vertex = i;
        }
    }
    return make_pair(mx, vertex);
}
void b(int u,int p=0){
  P[u]=p;
  for(auto i:a[u]){
    if(i!=p)b(i,u);
  }
}
void B(){
  vis=vector<int> (n+1, 0);
  dist=vector<int> (n+1, 0);
  auto g=d;
  while(g.empty()==0){
    vis[g.front()]=1;
    g.pop();
  }
  while(d.empty()==0){
    auto x=d.front();
    d.pop();
    for(auto y:a[x])if(vis[y]==0){
      d.push(y);
      vis[y]=1;
      dist[y] = dist[x] + 1;
    }
  }
  int mx = INT_MIN, vertex = -1;
    for(int i=1 ; i<=n ; i++){
        if(mx < dist[i]){
            mx = dist[i];
            vertex = i;
        }
    }
    dc=mx;
    c= vertex;
}
void diameter(int root){
    pair<int, int> p1 = bfs(root), p2;
    p2 = bfs(p1.second);
    dia=p2.F;
    D={p1.S,p2.S};
    b(p2.S);
    int x=p1.S;
    // d.push(p2.S)
    while(x!=0){
      d.push(x);
      // if(x==p1.S)break;
      x=P[x];
      // cout<<x;
    }
    B();
    if(dia==n){
      cout<<n-1<<"\n";
      cout<<D.F<<" "<<D.S<<" ";
      for(int i=1;i<=n;i++)if(i!=D.F and i!=D.S){
        cout<<i;break;
      }
      return;
    }
    cout<<dc+dia-1<<"\n";
    cout<<D.F<<" "<<D.S<<" "<<c;
}
void solve(){
  cin>>n;
  a=vector<vector<int>>(n+3);
  for(int i=1;i<=n-1;i++){
    cin>>x>>y;
    a[x].pb(y),a[y].pb(x);
  }
  diameter(1);
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
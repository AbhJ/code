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
/*
7
2 2 3
3 1 6 7
3 1 4 5
1 3
1 3
1 2
1 2
*/
int n,P[N],l,pos;vector<int>nodes,dist,vis(N,0);set<int>B,W;vector<vector<int>>a;
pair<int, int> bfs(int root){
    dist=vector<int> (n+1, 0);
    dist[root] = 1;
    queue<pair<int,int>> q;
    q.push({1,0});
    while(!q.empty()){
        auto curr = q.front();
        if(curr.S>l)l=curr.S,pos=curr.F;
        for(auto it : a[curr.F]){
            if(dist[it] != 0){
                continue;
            }
            q.push({it,curr.S+1});
            dist[it] = dist[curr.F] + 1;
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
void b(int u,int len=0,int s=pos){
  nodes.pb(u);
  vis[u]=1;
  if(len>l){
    B.clear();W.clear();
    l=len;
  }
  if(l==len){
    W.insert(u);
    W.insert(s);
    if(len&1){
      B.insert(nodes[len/2 +1]);
    }
    B.insert(nodes[len/2]);
  }
  for(auto i:a[u]){
    if(vis[i]==0)b(i,len+1,s);
  }
  vis[u]=0;
  nodes.pop_back();
}
void solve(){
  cin>>n;
  a=vector<vector<int>>(n+3);
  nodes.clear();B.clear();W.clear();
  dist.clear();vis.clear();l=pos=0;
  for(int i=1;i<=n;i++){
    int x,y;cin>>x;
    while(x--){cin>>y;a[i].pb(y);}
  }
  bfs(1);
  b(pos);
  for(auto i:W)if(i!=pos){pos=i;break;}
  vis.clear();
  nodes.clear();
  b(pos);
  // cout<<l;
  cout<<"Best Roots  :";
  for(auto i:B)cout<<" "<<i;
  cout<<"\nWorst Roots :";
  for(auto i:W)cout<<" "<<i;
  // for(int i=1;i<=n;i++){

  // }
  // cout<<y;
}
int32_t main()
{
  // ibs;cti;
  while(1)solve()
  ,cout<<"\n";
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();/*cout<<"\n";*/}
  return 0;
}
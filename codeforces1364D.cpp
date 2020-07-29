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
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,k,u,v,vis[N]; vi a[N];set<int> d;
// void bfs(int i){
//   vis[i]=1;
//   queue<pii>q;
//   q.push({i,0});
//   while(q.empty()==0){
//     int x=q.front().F;bool ok=q.front().S;q.pop();
//     d[ok].insert(x);
//     for(auto y:a[x]){
//       if(vis[y]==0){
//         vis[y]=1;
//         q.push({y,ok^1});
//       }
//     }
//   }
// }
stack<int>s;int D[N];
void dfs(int i,int p=0){
  vis[i]=1;
  s.push(i);
  D[i]=s.size();
  for(auto x:a[i]){
    if(vis[x]==0){
      if(d.count(i)==0)d.insert(x);
      dfs(x,i);
    }
    else if(x!=p){
      if(D[i]-D[x]+1<=k and D[i]-D[x]+1>=2){
        cout<<2<<"\n";
        cout<<D[i]-D[x]+1<<"\n";
        int z=D[i]-D[x]+1;
        while(z--)
          {cout<<s.top()<<" ";s.pop();}
        exit(0);
      }
    }
  }
  s.pop();
}
void solve(){
  cin>>n>>m>>k;
  rep(i,1,m){
    cin>>u>>v;
    a[u].pb(v),a[v].pb(u);
  }
  dfs(1);
  memset(vis,0,sizeof vis);
    // bfs(1);
    if(((k+1)/2)<=d.size()){
      cout<<1<<"\n";
      int c=0;
      for(auto i:d){cout<<i<<" ";if(++c==(k+1)/2)return;}
    }
    cout<<1<<"\n";
    rep(i,1,n){
      int c=0;
      if(d.count(i)==0)c++,cout<<i<<" ";
      if(c==(k+1>>1))break;
    }
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
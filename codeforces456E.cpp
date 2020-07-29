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
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
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
int n,m,q,x,y,t,parent[N],ind[N],vis[N],ok[N];vi a[N];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        ind[a]=max(((ind[a]+1)/2) +( (ind[b]+1)/2) +1,max(ind[a],ind[b]));
        parent[b] = a;
    }
}
int f,dis,baaap;
void dfs1(int u,int d=0){
  vis[u]=1;
  ok[u]=1;
  parent[u]=baaap;
  if(d>dis)dis=d,f=u;
  for(auto i:a[u])if(ok[i]==0){
    dfs1(i,d+1);
  }
}
void dfs2(int u,int d=0){
  vis[u]=1;
  ok[u]=0;
  parent[u]=baaap;
  if(d>dis)dis=d,f=u;
  for(auto i:a[u])if(ok[i]==1){
    dfs2(i,d+1);
  }
}
void solve(){
  cin>>n>>m>>q;
  rep(i,1,m){
    cin>>x>>y;
    a[x].pb(y),a[y].pb(x);
  }
  rep(i,1,n)if(parent[i]==0){
      baaap=i;
      dis=-1;dfs1(i);
      dis=-1;dfs2(f);
      ind[i]=dis;
  }
  rep(i,1,q){
    cin>>t>>x;
    if(t==1){
      cout<<ind[find_set(x)]<<"\n";
    }
    if(t==2){
      cin>>y;
      union_sets(x,y);
    }
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
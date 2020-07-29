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
#define pb emplace_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
#define deb(x) cout<<"\n["<<#x<<" = "<<x<<"]\n";
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
const int N=1e4+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,x,y,vis[N],dp[N][2],back[N][2],d[N],cnt_back[2];
vpii a[N];set<int>s[2];map<int,int>spanning_edge;vi ans;
void dfs(int u,int p=-1){
  vis[u]=1;
  for(auto z:a[u])if(z.F!=p){
    int i=z.F,num=z.S;
    if(vis[i]==0){
      d[i]=d[u]+1;
      spanning_edge[i]=num;
      dfs(i,u);
      dp[u][0]+=dp[i][0];
      dp[u][1]+=dp[i][1];
    }
    else if(d[i]<d[u]){
      //back edge to i from u
      int dis=(d[u]-d[i])&1;
      cnt_back[dis]++;
      back[u][dis]++;
      back[i][dis]--;
      s[dis].insert(num);
      //back[i] stores number of back edges up - number of back edges down
    }
  }
  dp[u][0]+=back[u][0];
  dp[u][1]+=back[u][1];
}
void solve(){
    cin>>n>>m;
    rep(i,1,m){
        cin>>x>>y;
        a[x].pb(pii{y,i});
        a[y].pb(pii{x,i});
    }
    rep(i,1,n)if(vis[i]==0)dfs(i);
    if(cnt_back[0]==0){
      //all back edges are part of bipartite graph
      cout<<m<<"\n";
      rep(i,1,m)cout<<i<<" ";
      return;
    }
    //now we consider only dis 0 back edges each of which on removal
    //makes graph bipartite
    rep(i,1,m)if(s[0].count(i)==1 and cnt_back[0]==1){
      ans.pb(i);
    }
    rep(i,1,n)if(cnt_back[0]==dp[i][0] and dp[i][1]==0){
      ans.pb(spanning_edge[i]);
    }
    cout<<ans.size()<<"\n";
    sort(all(ans));
    for(auto i:ans)cout<<i<<" ";
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
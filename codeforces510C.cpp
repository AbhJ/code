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
string s[N];vi a[N],vis(300,0);stack<int>S;set<int>A;int F,T;
void dfs(int u){
  vis[u]=T++;
  for(auto i:a[u]){
    if(vis[i]==0)dfs(i);
  }
  if(A.count(u))S.push(u),A.erase(u);
}
void solve(){
  int n;cin>>n;
  rep(i,0,n-1)cin>>s[i];
  rep(i,0,n-2){
    int m=0;
    while(s[i][m]==s[i+1][m]){
      m++;
    }
    if(s[i][m]!=s[i+1][m])a[s[i][m]].pb(s[i+1][m]);
  }
  rep(i,'a','z')A.insert(i);
  rep(i,'a','z'){
    if(vis[i]==0 and a[i].empty()==0)dfs(i);
  }
  string ans;
  vi tag(300,0);
  for(auto i:A)ans+=(char)i;
  while(S.empty()==0){
    ans+=(char)S.top();S.pop();
  }
  F=0;
  for(auto i:ans){
    tag[i]=F++;
  }
  rep(i,0,n-2){
    int m=0;
    while(s[i][m]==s[i+1][m]){
      m++;
    }
    if(s[i][m]!=s[i+1][m] and tag[s[i][m]]>tag[s[i+1][m]])
      cout<<"Impossible",exit(0);
  }
  cout<<ans;
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
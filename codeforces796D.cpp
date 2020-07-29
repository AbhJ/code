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
int n,k,d,p[N],dep[N],vis[N],x,y;vi a[N];vi dp;set<pii>S;
void dfs(int u,int p=-1,int d=0){
	dep[u]=d;
	if(p!=-1)dp[u]=min(dp[u],dp[p]+1);
	for(auto i:a[u])if(i!=p){
		dfs(i,u,d+1);
		dp[u]=min(dp[u],dp[i]+1);
	}
	// for(auto i:a[u])if(i!=p){

	// }
}
queue<pii>q;
void bfs(){
	// queue<pii>q;
	// q.push({0,s});
	while(q.empty()==0){
		auto x=q.front();q.pop();
		if(vis[x.S]==1)continue;
		vis[x.S]=1;
		for(auto i:a[x.S])if(i!=x.F){
			if(vis[i]==0/* and x.F+1<=d*/){
				q.push({x.S,i});
			}
			else/* if(x.F+1>d)*/{
				if(S.count({i,x.S})==0)S.insert({x.S,i});
				// q.push({x.F+1,i});
			}
		}
	}
}
void solve(){
	cin>>n>>k>>d;map<pii,int>m;
	dp=vi(n+1,inf);
	rep(i,1,k){
		cin>>p[i];
		// dp[p[i]]=0;
	}
	rep(i,1,n-1){cin>>x>>y,a[x].pb(y),a[y].pb(x);
		m[{x,y}]=m[{y,x}]=i;}
	rep(i,1,k){
		q.push({0,p[i]})/*for(auto i:S)cout<<m[i]<<" "<<"\n";*/;
	}
	bfs();
	cout<<S.size()<<"\n";
	for(auto i:S)cout<<m[i]<<" ";
	// rep(i,1,n)cout<<dp[i]<<" ";
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
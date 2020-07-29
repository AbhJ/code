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
bool vis[N];
vector<pair<int,int> > v;
vector<int>a[N];
void bfs(int s){
	queue<int>q;
	vis[s]=1;
	q.push(s);
	while(q.empty()==0){
		int x=q.front();q.pop();

		vis[x]=1;
		for (auto i:a[x])
			if(vis[i]==0)
				vis[i]=1,v.pb({x,i}),q.push(i);
	}
}
void solve(){
  int n,m;cin>>n>>m;
  int vvv=-1,ma=-1;
  for (int i = 0; i < m; ++i)
  {
  	int x,y;cin>>x>>y;
  	a[x].pb(y),a[y].pb(x);
  	if((int)a[x].size()>ma)vvv=x,ma=(int)a[x].size();
  	if((int)a[y].size()>ma)vvv=y,ma=(int)a[y].size();
  }
  // cout<<vvv;
  bfs(vvv);
  for(auto i:v)cout<<i.F<<" "<<i.S<<"\n";
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}
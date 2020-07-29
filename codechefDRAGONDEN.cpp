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
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
stack<int>s;int n,q,h[N],l[N],r[N],A[N],en1[N],en2[N],ex1[N],ex2[N],T,t[2][10*N],tree_builder[2][2*N],x;
vi a1[N],a2[N];
/*
8 3
1 2 3 2 1 2 3 4
1 1 1 1 1 1 1 1 
*/
void build(int v=1, int tl=0, int tr=2*(n+1)) {
    if (tl == tr) {
        t[x][v] = tree_builder[x][tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[x][v] = t[x][v*2] + t[x][v*2+1];
    }
}
//queries
int sum(int l, int r,int v=1, int tl=0, int tr=2*(n+1)) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr)
        return t[x][v];
    int tm = (tl + tr) / 2;
    return sum( l, min(r, tm),v*2, tl, tm)
           + sum(max(l, tm+1), r,v*2+1, tm+1, tr );
}
//
void update(int pos, int new_val,int v=1, int tl=0, int tr=2*(n+1)) {
    if (tl == tr) {
        t[x][v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos,new_val,v*2, tl, tm);
        else
            update(pos,new_val,v*2+1, tm+1, tr);
        t[x][v] = t[x][v*2] + t[x][v*2+1];
    }
}
void dfs1(int u,int p=-1){
	en1[u]=T++;
	for(auto i:a1[u])if(i!=p){
		dfs1(i,u);
	}
	ex1[u]=T++;
}
void flatten1(){
	int root=0;
	rep(i,0,n){
		if(l[i]==-1)root=i;
		else a1[l[i]].pb(i),a1[i].pb(l[i]);
	}
	T=0;
	dfs1(root);
	rep(i,0,n){
		tree_builder[0][en1[i]]=A[i];
		tree_builder[0][ex1[i]]=-A[i];
	}
	// rep(i,0,2*(n+1)-1)cout<<tree_builder[0][i];
	// // n++;
	// cout<<"\n";
	x=0;
	build();
}
void dfs2(int u,int p=-1){
	en2[u]=T++;
	for(auto i:a2[u])if(i!=p){
		dfs2(i,u);
	}
	ex2[u]=T++;
}
void flatten2(){
	int root=0;
	rep(i,0,n){
		if(r[i]==-1)root=i;
		else a2[r[i]].pb(i),a2[i].pb(r[i]);
	}
	T=0;
	dfs2(root);
	rep(i,0,n){
		tree_builder[1][en2[i]]=A[i];
		tree_builder[1][ex2[i]]=-A[i];
	}
	// rep(i,0,2*(n+1)-1)cout<<tree_builder[1][i];
	// cout<<"\n";
	x=1;
	build();
}
void solve(){
	cin>>n>>q;
	rep(i,1,n)cin>>h[i];
	r[0]=l[0]=-1;
	rep(i,1,n)cin>>A[i];
	rep(i,1,n){
		while(s.empty()==0 and h[s.top()]<=h[i])s.pop();
		if(s.empty()==0)l[i]=s.top();
		s.push(i);
	}
	// rep(i,1,n)cout<<l[i];
	s=stack<int>();
	per(i,n,1){
		while(s.empty()==0 and h[s.top()]<=h[i])s.pop();
		if(s.empty()==0)r[i]=s.top();
		s.push(i);
	}
	// rep(i,1,n)cout<<r[i];
	T=0;flatten1();
	T=0;flatten2();
	rep(i,1,q){
		int z,b,c;
		cin>>z>>b>>c;
		if(z==1){
			x=0;
			update(en1[b],c);
			update(ex1[b],-c);
			x=1;
			update(en2[b],c);
			update(ex2[b],-c);
			continue;
		}
		if(z==2){
			if(b<=c){
				x=0;
				if(en1[b]<=en1[c] and ex1[b]>=ex1[c])cout<<sum(en1[b],en1[c]);
				else cout<<-1;
			}
			if(c<b){
				x=1;
				if(en2[b]<=en2[c] and ex2[b]>=ex2[c])cout<<sum(en2[b],en2[c]);
				else cout<<-1;
			}
			cout<<"\n";
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
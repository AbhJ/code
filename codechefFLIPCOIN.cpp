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
const int N=1e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,z,l,r,t[4*N],x[4*N],a[N];
//x contains the xor
//t[i][j] contains num for jth bit
//building the tree
void push(int v,int tl,int tr){
	int tm=tl+tr>>1;
	if(x[v]==0)return;
	t[v<<1]=tm-tl+1-t[v<<1];
	t[v<<1|1]=tr-(tm+1)+1-t[v<<1|1];
	x[v<<1]^=x[v];
	x[v<<1|1]^=x[v];
	x[v]=0;
}
//queries
int sum(int l, int r,int v=1, int tl=1, int tr=n ) {
    if (l>r or tl>r or tr<l)return 0;
    if (tl>=l and tr<=r){
    	return t[v];
	}
	push(v,tl,tr);
    int tm=(tl+tr)/2;
    return sum( l,r,v<<1, tl, tm)
           + sum(l, r,v<<1|1, tm+1, tr );
}
void update(int l,int r,int tl=1,int tr=n,int v=1){
  if(tl>tr or tl>r or tr<l)return;
  if(tl>=l and tr<=r){
  	x[v]^=1;
  	t[v]=tr-tl+1-t[v];
  	return;
  }
  push(v,tl,tr);
  int mid=(tr+tl)/2;
  update(l,r,tl,mid,v<<1);
  update(l,r,mid+1,tr,v<<1|1);
  t[v]=t[v<<1]+t[v<<1|1];
}
void solve(){
	cin>>n>>m;
	rep(i,1,m){
		cin>>z>>l>>r;
		if(z==0){
			update(l+1,r+1);
		}
		if(z==1){
			cout<<sum(l+1,r+1)<<"\n";
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
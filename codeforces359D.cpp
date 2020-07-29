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
int a[N],l[N],r[N];stack<int>s;
void solve(){
	int n;cin>>n;
	rep(i,1,n)cin>>a[i];
	rep(i,1,n){
		while(s.empty()==0 and (a[s.top()]%a[i])==0)s.pop();
		if(s.empty()==0)l[i]=s.top();
		s.push(i);
	}
	rep(i,1,n)++l[i],r[i]=n+1;
	while(s.empty()==0)s.pop();
	per(i,n,1){
		while(s.empty()==0 and (a[s.top()]%a[i])==0)s.pop();
		if(s.empty()==0)r[i]=s.top();
		s.push(i);
	}
	rep(i,1,n)--r[i];
	vi vis(n+1,0);
	priority_queue<pair<int,pii>>q;
	rep(i,1,n){
		q.push({r[i]-l[i],{l[i],r[i]}});
	}
	int ma=-1;set<int>ans;
	while(q.empty()==0){
		auto x=q.top();q.pop();
		int L=x.S.F,R=x.S.S,len=x.F;
		if(ma==-1)ma=len;
		else{
			if(len!=ma)break;
		}
		ans.insert(L);
	}
	cout<<ans.size()<<" "<<ma<<"\n";
	for(auto i:ans)cout<<i<<" ";
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
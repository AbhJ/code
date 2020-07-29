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
int val[N][2];
ll powM(ll b, int p,int M) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
int f(int n){
	int cnt=0;
	while(n){
		cnt++,n%=__builtin_popcount(n);
	}
	return cnt;
}
void solve(){
	int n;cin>>n;
	bitset<N>a;cin>>a;
	int set=a.count();
	int n1=set+1,n2=set-1;
	int ans1=0,ans2=0;
	val[0][0]=val[0][1]=1;
	rep(i,0,n-1){
		val[i+1][0]=2*val[i][0]%n1;
		if(n2!=0)val[i+1][1]=2*val[i][1]%n2;
		if(a[i]==1)ans1+=val[i][0],ans2+=val[i][1];
	}
	per(i,n-1,0){
		if(a[i]==1){
			if(n2==0){cout<<0<<" ";continue;}
			int cnt=ans2-val[i][1]+n2;
			cnt%=n2;
			cout<<1+f(cnt);
		}
		else{
			int cnt=ans1+val[i][0];
			cnt%=n1;
			cout<<1+f(cnt);
		}
		cout<<"\n";
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
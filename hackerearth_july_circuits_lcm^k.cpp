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
const int N=1e6+20;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,k,a[N],v[N],sp[N];
int mul(int a,int b){
	return a*b%m;
}
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%m, p/=2)
    if(p&1)
      r=r*b%m;
  return r;
}
void Sieve(){
  for (int i = 2; i < 1e6+10; i += 2)  sp[i] = 2;//even numbers have smallest prime factor 2
  for (int  i = 3; i < 1e6+10; i += 2){
    if (!v[i]){
      sp[i] = i;
      for (int j = i; (j*i) < 1e6+10; j += 2){
        if (!v[j*i])  v[j*i] = true, sp[j*i] = i;
      }
    }
  }
}
vi c(N,0);
void solve(){
	cin>>n>>m>>k;c=vi(N,0);
	rep(i,1,n)cin>>a[i];
	rep(i,1,n){
		int spf=sp[a[i]];
		while(spf!=0){
			int cnt=1;
			while((a[i]%spf)==0)a[i]/=spf,cnt*=spf;
			c[spf]=max(c[spf],cnt);
			spf=sp[a[i]];
		}
	}
	int ans=1;
	rep(i,0,N-1){
		if(c[i])/*cout<<i<<" "<<c[i]<<"\n",*/ans=mul(ans,c[i]);
	}
	ans=powM(ans,k);
	cout<<ans;
}
int32_t main()
{
  ibs;cti;
  Sieve();
  // solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
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
vi KMP(string s){
    int n=s.length();
    vi pi(n,0);
    rep(i,1,n-1){
        int j=pi[i-1];
        while(j and (s[i]!=s[j]))
            j=pi[j-1];
        if(s[i]==s[j])s[i]=s[j],j++;
        pi[i]=j;
    }
    return pi;
}
int dp[N],g[N];
void solve(){
    string s,t;cin>>s>>t;
    int n=s.length(),m=t.length();
    auto pi=KMP(t);
    rep(i,m-1,n-1){
    	bool f=1;
    	rep(j,0,m-1){
    		if(s[i-j]!=t[m-1-j] and s[i-j]!='?')
    			f=0;
    	}
    	dp[i]=dp[i-1];
    	if(f==0)continue;
    	g[i]=dp[i-m];
    	for(int j=pi[m-1];j!=0;j=pi[j-1])
    		g[i]=max(g[i],g[i+j-m]);
    	g[i]++;
    	dp[i]=max(dp[i],g[i]);
    }
    cout<<dp[n-1];
}
int32_t main()
{
  ibs;cti;
  solve();
  /*,cout<<"\n"*/
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
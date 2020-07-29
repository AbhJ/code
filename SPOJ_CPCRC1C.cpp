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
vector<vvi> dp;string a;
int f(int pos=0,bool ok=0,int sum=0,int lim=9){
  if(pos==a.length())return sum;
  if(dp[pos][ok][sum])return dp[pos][ok][sum];
  if(ok==0)lim=a[pos]-'0';
  int ans=0;
  rep(i,0,lim){
    if(ok==0 and i==lim) ans+=f(pos+1,0,sum+i);
    else ans+=f(pos+1,1,sum+i);
  }
  return dp[pos][ok][sum]=ans;
}
void solve(){
  int x,y;cin>>x>>y;
  if(x==-1)exit(0);
  dp=vector<vvi>(20,vvi(2,vi(1000,0)));
  a=to_string(y);
  int high=f();
  dp=vector<vvi>(20,vvi(2,vi(1000,0)));
  a=to_string(x-1);
  if(x-1!=-1)high-=f();
  cout<<high;
}
int32_t main()
{
  // ibs;cti;
  while(1)solve()
  ,cout<<"\n";
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
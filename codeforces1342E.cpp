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
const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
int add(int a, int b){
  a+=b;
  if(a>=M)a-=M;
  return a;
}
int mul(int a,int b){
  return a*b%M;
}
int sub(int a,int b){
  return add(a,M-b);
}
int f[N],b[N];
void calc_fact(){
  f[0]=b[0]=1;
  rep(i,1,N-1){
    f[i]=mul(f[i-1],i);
    b[i]=powM(f[i],M-2);
  }
}
int C(int n,int r){
  return (f[n]*((b[r]*b[n-r])%M))%M;
}
//dp[i] is number of ways to fill i rooks till this column
void solve(){
  int n,k,m,ans=0;cin>>n>>k;
  //each row must have exactly one rook
  //if we choose m columns to be filled number of pairs is n-m = k
  //i.e m=n-k
  m=n-k;
  if(k>=n){cout<<0;return;}
  //the follwing computes sterling number {n,m}
  //that is number of ways to distribute n rooks in m columns as a set
  rep(i,0,m){
    int x=mul(C(m,i),powM(m-i,n));
    if((i&1))ans=sub(ans,x);
    else ans=add(ans,x);
  }
  ans=mul(ans,C(n,m));
  if(k!=0)ans=mul(ans,2);//we could have also placed one rook per column
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  calc_fact();
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
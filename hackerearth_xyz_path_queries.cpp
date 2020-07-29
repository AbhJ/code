// //Coded by Abhijay Mitra
// #include <iostream>
// #include <stdlib.h>
// #include <algorithm>
// #include <cstdio>
// #include <numeric>
// #include <cstring>
// #include <numeric>
// #include <vector>
// #include <iterator> 
// #include <map>
// #include <set>
// #include <climits>
// #include <queue>
// #include <cmath>
// #include <stack>
// #include <cctype>
// #include <bitset>
#include <bits/stdc++.h>
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb emplace_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
#define deb(x) cout<<"\n["<<#x<<" = "<<x<<"]\n";
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
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,A[N],B[N][70],dp[N][70],tot,one,zero,ans,q,t,x,y,f[N],b[N],MOD=M;vi height,first,euler,T;vvi a;
void dfs(int u,int h=0,int p=0){
  euler.pb(u);
  height[u]=h++;
  first[u]=euler.size()-1;
  rep(i,0,30)dp[u][i]=dp[p][i]+B[u][i];
  for(auto i:a[u])if(i!=p){
    dfs(i,h,u);
    euler.pb(u);
  }
}
void build(int v=1, int tl=0, int tr=euler.size()-1) {
    if (tl == tr) {
        T[v] = euler[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        T[v]=(height[T[v*2]]<height[T[v*2+1]]?T[v*2]:T[v*2+1]);
    }
}
//queries
int sum(int l, int r,int v=1, int tl=0, int tr=euler.size()-1) {
    if (l > r) 
        return inf;
    if (l == tl && r == tr)
        return T[v];
    int tm = (tl + tr) / 2;
    int s1= sum( l, min(r, tm),v*2, tl, tm);
    int s2= sum(max(l, tm+1), r,v*2+1, tm+1, tr );
    if(s1==inf)return s2;
    if(s2==inf)return s1;
    return (height[s1]<height[s2])?s1:s2;
}
int qu(int x,int y){
  x=first[x],y=first[y];
  if(x>y)swap(x,y);
  return sum(x,y);
}
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
int C(int n,int r){
  assert(n<N);assert(r<N);
  if(r>n)return 0;
  int ret = (f[n]*b[r])%MOD;
  return (ret*b[n-r])%MOD;
}
int add(int a,int b){
  a+=b;
  // if(a>=M)a%=M;
  return a%M;
}
int mul(int a,int b){
  return ((a%M)*(b%M))%M;
}
void calc_fact(){
  f[0]=b[0]=1;
  rep(i,1,N-1){
    f[i]=mul(f[i-1],i);
    b[i]=powM(f[i],M-2);
  }
}
void solve(){
  cin>>n;
  rep(i,1,n)cin>>A[i];height=first=vi(n+1,0);a.resize(n+1);a.clear();
  rep(i,1,n-1)cin>>x>>y,a[x].pb(y),a[y].pb(x);
  rep(i,1,n)
    rep(j,0,30)
          B[i][j]=!!(A[i]&(1<<j));
  dfs(1);cin>>q;
  T=vi(euler.size()*4LL,0LL);build();
  while(q--){
    cin>>t>>x>>y;
    int l=qu(x,y);
    // cout<<l<<"\n";
    ans=0;
    tot=height[x]+height[y]-2*height[l]+1;
    rep(i,0,30){
      one=dp[x][i]+dp[y][i]-2*dp[l][i]+B[l][i];
      zero=tot-one;
      if(t==1)ans=add(ans,one<<i);
      if(t==2)ans=add(ans,mul(add(C(one,2),mul(C(zero,1),C(one,1))),(1LL<<i)%M));
      //both can be set or one can be set
      if(t==3)ans=add(ans,mul(add(C(one,3),add(mul(C(one,2),C(zero,1)),mul(C(one,1),C(zero,2)))),(1LL<<i)%M));
      //3 can be set or 2 can be set or one can be set
      if(t==4)ans=add(ans,mul(add(C(one,4),add(mul(C(one,3),C(zero,1)),add(mul(C(one,2),C(zero,2)),mul(C(one,1),C(zero,3))))),(1LL<<i)%M));
      //4 can be set or 3 or 2 or 1
    }
    cout<<ans<<"\n";
  }
}
int32_t main()
{
  ibs;cti;calc_fact();
  solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
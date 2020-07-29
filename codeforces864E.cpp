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
// #define int long long int
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
const int N=1e2+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,t[N],d[N],p[N],pos[N],dp[102][2002][2];/*map<pii,int>m;*/
bool cmp(int x,int y){
  if(d[x]==d[y])return p[x]>p[y];
  return d[x]<d[y];
}
void solve(){
  cin>>n;
  rep(i,1,n){
    cin>>t[i]>>d[i]>>p[i];pos[i]=i;
  }
  sort(pos+1,pos+1+n,cmp);
  //dp[i][j][0] is optimal cost of items saved looking till ith item and 
  //j total time
  // rep(i,1,n)cout<<pos[i];
  rep(cnt,1,n){
    rep(j,0,2000){
      int i=pos[cnt],last=pos[cnt-1];
      if(t[i]<=j and dp[i][j][0]<p[i]+dp[last][j-t[i]][0] and j<d[i])
        dp[i][j][0]=p[i]+dp[last][j-t[i]][0],
        dp[i][j][1]=1+dp[last][j-t[i]][1];
      if(dp[i][j][0]<dp[last][j][0])
        dp[i][j][0]=dp[last][j][0],
        dp[i][j][1]=dp[last][j][1];
    }
  }
  // cout<<dp[1][2][0];
  int ind,val=-inf,ans=0;
  rep(j,0,2000){
    int i=pos[n];
    if(dp[i][j][0]>val){
      val=dp[i][j][0],ind=j,ans=dp[i][j][1];
    }
  }
  cout<<val<<"\n";
  vi v;int j=ind;
  per(cnt,n,1){
    int i=pos[cnt],last=pos[cnt-1];
    if(j>=t[i] and p[i]+dp[last][j-t[i]][0]==dp[i][j][0])j-=t[i],v.pb(i);
  }
  cout<<v.size()<<"\n";
  reverse(all(v));
  for(auto i:v)cout<<i<<" ";
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
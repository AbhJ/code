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
int a[N],s[N][10],pos[N]; 
bool cmp(int x,int y){
  return a[x]>a[y];
}
void solve(){
  int n,p,k;cin>>n>>p>>k;vvi dp(n+1,vi((1<<p),-inf));
  dp[0][0]=0;
  rep(i,1,n)cin>>a[i];
  rep(i,1,n)rep(j,0,p-1)cin>>s[i][j];
  rep(i,1,n)pos[i]=i;
  sort(pos+1,pos+n+1,cmp);
  rep(i,1,n){
    rep(mask,0,(1<<p)-1){
      int not_selected=i-1-__builtin_popcount(mask);dp[i][mask]=dp[i-1][mask];
      rep(j,0,p-1){
        if((1<<j)&mask)dp[i][mask]=max(dp[i][mask],dp[i-1][mask^(1<<j)]+s[pos[i]][j]);
        if(not_selected<k){
              dp[i][mask]=max(dp[i][mask],dp[i-1][mask]+a[pos[i]]);
            }
      }
    }
  }
  cout<<dp[n][(1<<p)-1];
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
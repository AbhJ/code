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
int n, a[N], pos[N];
bool cmp(int x,int y){
  return a[x]<a[y];
}
void solve(){
  cin>>n;vvi dp(n+1,vi(1010,0));vi ans(n+1,0),ma(1010,0);
  dp[0][0]=1;
  rep(i,1,n){cin>>a[i];pos[i]=i;ma[a[i]]++;}
  sort(pos+1,pos+n+1,cmp);
  // rep(i,1,n)cout<<a[pos[i]];
  //dp[i][j] = 1 if we can reach sum j using first i numbers
  rep(i,1,n){
    dp[i][0]=1;
    ans[pos[i]]|=dp[i-1][a[pos[i]]];
    ans[pos[i]]|=(ma[a[pos[i]]]>=2);
    rep(j,0,1009){
      dp[i][j]|=dp[i-1][j];
      if(j+a[pos[i]]<=1009)dp[i][j+a[pos[i]]]|=dp[i-1][j];
    }
  }
  rep(i,1,n)cout<<ans[i]<<" ";
}
int32_t main()
{
  ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
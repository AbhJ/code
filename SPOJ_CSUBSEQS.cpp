//Coded by Abhijay Mitra
#include <iostream>
#include <cstdlib>
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
const int N=5e1+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
string s,t,p,q;int dp[N][N][N][N];int L[N],P[300];
void solve(){
  cin>>s>>t>>p>>q;
  s='#'+s;
  t='#'+t;
  p='#'+p;
  q='#'+q;
  rep(i,0,s.length()-1){L[i]=P[s[i]],P[s[i]]=i;}
  rep(i,0,s.length()-1)
    rep(j,0,t.length()-1)
      rep(k,0,p.length()-1)
        rep(l,0,q.length()-1){
          if((i&&j&&k&&l)==0)dp[i][j][k][l]=1;
          //am confused about the following statement
          else if(s[i]==t[j] and t[j]==p[k] and p[k]==q[l]){
            dp[i][j][k][l]=dp[i-1][j][k][l]+dp[i-1][j-1][k-1][l-1];
            if(L[i]!=0)dp[i][j][k][l]-=dp[L[i]-1][j-1][k-1][l-1];
          }
          else{
            //using inclusion and exclusion principle pnc
            dp[i][j][k][l]=
            //singluar
            dp[i-1][j][k][l]+dp[i][j-1][k][l]+dp[i][j][k-1][l]+dp[i][j][k][l-1]
            //pairs
            -dp[i-1][j-1][k][l]-dp[i-1][j][k-1][l]-dp[i-1][j][k][l-1]-dp[i][j-1][k-1][l]-dp[i][j-1][k][l-1]-dp[i][j][k-1][l-1]
            //triplets
            +dp[i-1][j-1][k-1][l]+dp[i-1][j][k-1][l-1]+dp[i-1][j-1][k][l-1]+dp[i][j-1][k-1][l-1]
            //quadruplet
            -dp[i-1][j-1][k-1][l-1];
          }
        }
  cout<<dp[s.length()-1][t.length()-1][p.length()-1][q.length()-1]-1LL;
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
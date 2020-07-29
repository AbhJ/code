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
const int N=3e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
string s,t,dp[N][N];
void solve(){
  cin>>s>>t;int n=s.length(),m=t.length();
  //The below method uses no backtracking hence shows TLE,MLE
  // if(s[0]==t[0])dp[0][0]=s[0];
  // rep(i,0,n-1)
  //   rep(j,0,m-1){
  //     if(s[i]==t[j] and i!=0 and j!=0)dp[i][j]=dp[i-1][j-1]+s[i];
  //     if(s[i]!=t[j] and i!=0 and j!=0){
  //       string a=dp[i][j-1];
  //       string b=dp[i-1][j];
  //       if(a.length()>b.length())dp[i][j]=a;
  //       else dp[i][j]=b;
  //     }
  //     if(s[i]!=t[j] and i!=0 and j==0)dp[i][j]=dp[i-1][j];
  //     if(s[i]!=t[j] and i==0 and j!=0)dp[i][j]=dp[i][j-1];
  //     if(s[i]==t[j] and i!=0 and j==0)dp[i][j]=s[i];
  //     if(s[i]==t[j] and i==0 and j!=0)dp[i][j]=s[i];
  //   }
  // cout<<dp[n-1][m-1];
  //Using backtracking we generate the following piece of code
  vvi d(n,vi(m,0));
  if(s[0]==t[0])d[0][0]=1;
  rep(i,0,n-1)
    rep(j,0,m-1){
      if(s[i]==t[j] and i!=0 and j!=0)d[i][j]=d[i-1][j-1]+1;
      if(s[i]!=t[j] and i!=0 and j!=0){
        d[i][j]=max(d[i-1][j],d[i][j-1]);
      }
      if(s[i]!=t[j] and i!=0 and j==0)d[i][j]=d[i-1][j];
      if(s[i]!=t[j] and i==0 and j!=0)d[i][j]=d[i][j-1];
      if(s[i]==t[j] and i!=0 and j==0)d[i][j]=1;
      if(s[i]==t[j] and i==0 and j!=0)d[i][j]=1;
    }
  int i=n-1,j=m-1;string output;bool f=0;
  while(i!=0 or j!=0){
    if(i!=0 and j!=0 and s[i]==t[j])output=s[i]+output,i--,j--;
    else if(i!=0 and j!=0 and d[i][j-1]>d[i-1][j])j--;
    else if(i!=0 and j!=0 and d[i][j-1]<=d[i-1][j])i--;
    else if(i==0 and j!=0 and s[i]==t[j]){f=1;output=s[i]+output;break;}
    else if(i!=0 and j==0 and s[i]==t[j]){f=1;output=s[i]+output;break;}
    else if(i==0 and j!=0)j--;
    else if(j==0 and i!=0)i--;
  }
  if(s[0]==t[0] and f==0)cout<<s[0];
  cout<<output;
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
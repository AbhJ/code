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
string s[N];bool dp[101][101][1001];
void solve(){
  int n,m,k;cin>>n>>m>>k;
  rep(i,1,n)cin>>s[i],s[i]='#'+s[i];
  rep(i,1,n){
    rep(j,1,m){
      rep(num,0,1000){
        int req=num-(s[i][j]-'0');
        if(req==0){dp[i][j][num]=1;continue;}
        if(req<0)continue;
        dp[i][j][num]|=dp[i-1][j-1][req];
        dp[i][j][num]|=dp[i-1][j+1][req];
      }
    }
  }
  int c=0,v;
  per(num,9*n,0){
    rep(j,1,m)
      if(dp[n][j][num]==1 and num%(k+1)==0){c=j,v=num;break;}
    if(c!=0)break;
  }
  if(c==0)cout<<-1,exit(0);
  int fv=v,fc=c;
  string ans;int i=n;
  while(i!=1){
    v-=(s[i][c]-'0');
    if(dp[i-1][c-1][v]==1)c--,ans+='L';
    else if(dp[i-1][c+1][v]==1)c++,ans+='R';
    i--;
  }
  if(ans.length()==n-1){
    cout<<fv<<"\n"<<fc<<"\n";
    cout<<ans;
  }
  else cout<<-1;
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
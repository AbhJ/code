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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,q,x,y;string tester,s;deque<string>a;
int add(int a,int b){
  a+=b;
  if(a>=M)a-=M;
  return a;
}
void solve(){
  cin>>n>>q;
  while(q--){
    cin>>tester;
    if(tester=="add"){
      cin>>s;
      a.push_back(s);
    }
    if(tester=="remove"){
      a.pop_front();
    }
    if(tester=="path"){
      cin>>x>>y;
      x--,y--;
      vvi dp(a.size(),vi(n,0));
      dp[0][x]=1;
      rep(i,1,a.size()-1){
        rep(j,0,n-1){
            if(a[i][j]==a[i-1][j])dp[i][j]=add(dp[i][j],dp[i-1][j]);
            if(j!=0)if(a[i][j]==a[i-1][j-1])dp[i][j]=add(dp[i][j],dp[i-1][j-1]);
            if(j!=n-1)if(a[i][j]==a[i-1][j+1])dp[i][j]=add(dp[i][j],dp[i-1][j+1]);
        }
      }
      cout<<dp[a.size()-1][y]<<"\n";
    }
  }
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
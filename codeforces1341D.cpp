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
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
vector<string> S{"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string s[N];int dp[N][N];
int cnt(string s){
  int ans=0;
  for(auto i:s){
    ans+=(i=='1');
  }
  return ans;
}
int ff(string s,int n){
  int ok=-1;int pos=-1;
  for(auto ss:S){
    pos++;
    bool F=0;int cost=0;
    rep(i,0,7){
      if(ss[i]=='0' and s[i]=='1')F=1;
      if(ss[i]=='1' and s[i]=='0')cost++;
    }
    if(F)continue;
    if(cost==n)ok=pos;
  }
  return ok;
}
int val[N][12],c[N][N];
int f(int i,int num){
  if(val[i][num])return val[i][num];
  rep(j,1,N){
    if(s[j]=="")break;
    rep(n,0,9){
      val[j][n]=ff(s[j],n);
    }
  }
  return val[i][num];
}
void precompute(){
  rep(i,1,N){
    rep(j,0,9){
      rep(k,0,6){
        if(s[i]=="")return;
        if(s[i][k]=='1' and S[j][k]=='0'){c[i][j]=-1;break;}
        if(s[i][k]=='0' and S[j][k]=='1'){c[i][j]++;}
      }
    }
  }
}
int pr[N][N],l[N];
void solve(){
  int n,k;cin>>n>>k;
  rep(i,1,n){
    cin>>s[i];
  }
  precompute();
  dp[n+1][0]=1;
  per(i,n,1){
    rep(j,0,k){
      if(dp[i+1][j]){
        rep(target,0,9){
          int cost=c[i][target];
          if(cost==-1)continue;
          dp[i][j+cost]|=dp[i+1][j];
        }
      }
    }
  }
  if(dp[1][k]==0)cout<<-1,exit(0);
  rep(i,1,n){
    per(j,9,0){
      if(k>=c[i][j] and c[i][j]!=-1 and dp[i+1][k-c[i][j]]==1){
        cout<<j;k-=c[i][j];break;
      }
    }
  }
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
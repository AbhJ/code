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
int n,m,k,sp[10][N][26];
int f(int L,int R){
  int j=(int)log2(R-L+1);
  int ans=0;
  rep(z,0,m-1){
    ans+=max(sp[z][L][j],sp[z][R-(1<<j)+1][j]);
  }
  return ans;
}
vi get(int L,int R){
  vi v(m,0);
  int j=(int)log2(R-L+1);
  rep(z,0,m-1){
    v[z]=max(sp[z][L][j],sp[z][R-(1<<j)+1][j]);
  }
  return v;
}
void solve(){
  cin>>n>>m>>k;
  rep(i,0,n-1){
    rep(j,0,m-1)cin>>sp[j][i][0];
  }
  rep(z,0,m-1)
    rep(j,1,25)
      rep(i,0,n-(1<<j)){
        sp[z][i][j]=max(sp[z][i][j-1],sp[z][i+(1<<(j-1))][j-1]);
      }
  int i=0;
  vector<int>v(m);
  int val=0;
  rep(j,0,n-1){
    i=max(i,j);
    while(f(j,i+1)<=k and i<n-1)i++;
    if(i-j+1>val and f(j,i)<=k)val=i-j+1,v=get(j,i);
  }
  rep(i,0,m-1)cout<<v[i]<<" ";
}
int32_t main()
{
  ibs;cti;
  // koto_memory(sp);
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
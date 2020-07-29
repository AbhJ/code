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
vvi v(8,vi(3,0));
int c(int i,int j){
  int ans=0;
  rep(k,0,2)ans+=(v[i][k]-v[j][k])*(v[i][k]-v[j][k]);
  return ans;
}
// int calc(){
//   set<vi>s;
//   rep(i,0,7)s.insert(v[i]);
//   if(s.size()!=8)return 0;
//   map<int,int>m;
//   rep(i,1,7){
//     m[c(0,i)]++;
//   }
//   vi ok;
//   for(auto i:m)ok.pb(i.S);
//   sort(all(ok));
//   return ok==vi{1,3,3};
// }
int calc(){
  set<int>s;
  rep(i,0,7)
    rep(j,i+1,7)
      s.insert(c(i,j));
  return s.size()==3;
}
int T;
void f(int st=1){
  if(st==8){
    if(calc()){
      cout<<"YES\n";
      rep(i,0,7){
        rep(j,0,2)cout<<v[i][j]<<" ";
        cout<<"\n";
      }
      exit(0);
    }
    return;
  }
  do{
    f(st+1);
  }while(next_permutation(all(v[st])));
  T++;
}
void solve(){
  rep(i,0,7){rep(j,0,2)cin>>v[i][j];sort(all(v[i]));}
  f();
  cout<<"NO\n";
  // cout<<T;
  // timer
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
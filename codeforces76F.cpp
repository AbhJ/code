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
bool c=0;int n;pii q[N];
int lis(){
  multiset<int> x;
  rep(i,1,n+1-1){
    if(c==1 and (q[i].F<0 or q[i].S<0))continue;
    auto it=x.upper_bound(q[i].S);
    if(x.end()!=it)x.erase(it);
    x.insert(q[i].S);
  }
  int ans=0;
  // rep(i,1,n+1)
    // if(d[i]<inf)ans=i;
  return x.size();
}
int x[N],t[N],v;
void solve(){
  cin>>n;bool ok=0;
  rep(i,1,n){cin>>x[i]>>t[i];if(x[i]==0 and t[i]==0)ok=1;}
  cin>>v;
  rep(i,1,n){
    q[i]={-x[i]+v*t[i],x[i]+v*t[i]};
  }
  sort(q+1,q+1+n);
  int ans=lis();c=1;
  cout<<lis()<<" "<<ans;
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
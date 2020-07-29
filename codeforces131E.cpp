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
int n,m,x,y,a[N],l[N],r[N],t[9];
void solve(){
  cin>>n>>m;
  map<int,set<int>>mx,my,md1,md2;
  rep(i,1,m){
    cin>>x>>y;l[i]=x;r[i]=y;
    mx[x].insert(y);
    my[y].insert(x);
    md1[x+y].insert(x);
    md2[x-y].insert(x);
  }
  rep(i,1,m){
    x=l[i],y=r[i];
    if(*mx[x].begin()<y)a[i]++;
    if(*mx[x].rbegin()>y)a[i]++;
    if(*my[y].begin()<x)a[i]++;
    if(*my[y].rbegin()>x)a[i]++;
    if(*md1[x+y].begin()<x)a[i]++;
    if(*md1[x+y].rbegin()>x)a[i]++;
    if(*md2[x-y].begin()<x)a[i]++;
    if(*md2[x-y].rbegin()>x)a[i]++;
    t[a[i]]++;
  }
  rep(i,0,8)cout<<t[i]<<" ";
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
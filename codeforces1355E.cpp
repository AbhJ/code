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
#include <iomanip>
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
#define res(vector) v.resize(unique(v.begin(), v.end()) - v.begin());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,a,r,m,A[N],p[N],ans;
int f(int h){
  int pos=prev(upper_bound(A+1,A+1+n,h))-A;
  int no_less=pos*h-p[pos],no_more=p[n]-p[pos]-(n-pos)*h;
  if(no_less<0 or no_more<0)return inf;
  // cout<<no_less<<no_more<<p[n]-pos<<" "<<(n-pos)*h<<" "<<"\n";
  if(no_more>=no_less)
  return (no_less)*m+(no_more-no_less)*r;
  return (no_more)*m+(no_less-no_more)*a;
}
void solve(){
  cin>>n>>a>>r>>m;m=min(m,a+r);
  for(int i=1;i<=n;i++)cin>>A[i];
  sort(A+1,A+1+n);
  for(int i=1;i<=n;i++)p[i]=p[i-1]+A[i];
  // f(3),f(4),f(6),f(8);<<
  ans=inf;
  ans=min(ans,f(p[n]/n));ans=min(ans,f(1+(p[n]/n)));
  for(int i=1;i<=n;i++){
    ans=min(ans,f(A[i]));
  }
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();/*cout<<"\n";*/}
  return 0;
}
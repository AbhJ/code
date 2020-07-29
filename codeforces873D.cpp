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
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,k,a[N],sum,num;
void m(int l,int r){
  if(k<=0 or r-l<2)return;
  k-=2;
  int M=l+r>>1;
  swap(a[M],a[M-1]);
  m(l,M);
  m(M,r);
}
void solve(){
  cin>>n>>k;
  for(int i=1;i<=n;i++)a[i]=i;
  if((k&1) == 0){cout<<-1;return;}
  --k;
  m(1,n+1);
  if(k!=0){cout<<-1;return;}
  for(int i=1;i<=n;i++)cout<<a[i]<<" ";
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
// 4 -1
// -2 1 -2 3
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <cstdio>
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
using namespace std;//coded by abhijay mitra
const int N=1e6+10;
const int inf = /*0x3f3f3f3f*/1e9;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int b[N],n,i,ma,x,hug,day,a[N];
void solve(){
  cin>>n>>x;
  for(i=1;i<=n;i++){cin>>b[i];b[n+i]=b[i];a[i]=(b[i]+1)*b[i]/2;a[n+i]=a[i];}
  i=1;
  for(int j=1;j<=2*n;j++){
    hug+=a[j];
    day+=b[j];
    while(day>x){
      if(day-b[i]<x)break;
      day-=b[i];
      hug-=a[i++];
    }
    ma=max(ma,hug-(max(day-x,0LL)*max(1LL,(day-x)+1)/2));
    // cout<<ma;
  }
  cout<<ma;
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
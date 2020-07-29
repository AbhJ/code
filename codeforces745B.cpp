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
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e9+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m; char a[N][N];
void solve(){
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>a[i][j];
  int mix=inf,mx=-inf,miy=inf,my=-inf,c=0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      if(a[i][j]=='X'){
        miy=min(j,miy);
        mix=min(i,mix);
        mx=max(i,mx);
        my=max(j,my);
        c++;
      }
  if((mix-mx-1)*(1+my-miy)+c==0)cout<<"YES\n";
  else cout<<"NO\n";
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
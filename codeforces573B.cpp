#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
// #include <numeric>
#include <vector>
// #include <iterator> 
// #include <map>
#include <set>
// #include <climits>
// #include <queue>
// #include <iomanip>
// #include <cmath>
// #include <stack>
#include <cctype>
// #include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const int inf = 0x3f3f3f3f;
const ll M = 998244353 ; // Mulo
// const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int a[N],b[N];
void solve(){
  int n;cin>>n;
  int x=0,ma=0;
  for (int i = 1; i <= n; ++i){
    cin>>a[i];
    x=min(x,a[i]-i);b[i]=i+x;
  }
  //from left
  x=n+1;
  for(int i=n;i>=1;i--){
    x=min(x,a[i]+i);b[i]=min(b[i],x-i);
    ma=max(ma,b[i]);
  }
  cout<<ma;
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}
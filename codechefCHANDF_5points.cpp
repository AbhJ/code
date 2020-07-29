#include <iostream>
#include <stdlib.h>
#include <algorithm>
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
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
ll x,y,l,r;
void solve(){
  cin>>x>>y>>l>>r;
  if(x==0){cout<<0;return;}
  else if(y==0 or r==0){cout<<0;return;}
  bitset<62>X(x),Y(y),R(r),z(0);
  bool c1=0,c2=0;
  // int h=max(log2(r),log2(x),log2(y));
  // cout<<h;
  bool beat=0;
  for (int i = 0; i <= log2(r); ++i)
  {
    z[i]=(X[i] | Y[i]);
    // if(beat==0 and R[i]==0 and z[i]==1)z[i]=0;
    // if(R[i]==1 and z[i]==0 and c1==1 and c2==1)beat=1;
    if(X[i] and z[i])c1=1;
    if(Y[i] and z[i])c2=1;
  }
  // cout<<log2(0);
  if(z.to_ullong()>r)
  for(int i=log2(r);i>=0;i--){
    if(z[i]==1){
      z[i]=0;break;
    }
  }
  if((z&X)==0 or (z&Y)==0)cout<<0;else
  cout<<z.to_ullong();
}
int main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;
  while(t--){solve();cout<<"\n";}
  return 0;
}
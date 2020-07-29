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
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=70;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int x,y,l,r,h,zz;double mi=0;
bitset<70>X,Y,R,final;
void calc_cost(bitset<70>doom,int n){
  bitset<70>z=doom;
  double cos=0;
  for (int i = n; i > -1; --i)
  {
    z[i]=(X[i]|Y[i]);
  }
  zz=z.to_ullong();
  // cout<<zz;
  if(zz>r)return;
  // if((zz&x)==0 or (zz&y)==0)return;
    // cout<<z<<"\n";
  cos=((zz&x)*(zz&y));
  // cout<<cos;
  if(cos==mi){if(z.to_ullong()<final.to_ullong())final=z;}
  else if(cos>mi){
    final=z;
    mi=cos;
  }
  // cout<<final<<"\n";
}
void f(){
  bitset<70>temp(0);
  calc_cost(temp,-1);
  while(--h!=-1){
    if(R[h]==1){
      temp[h]=0;calc_cost(temp,h-1);
    }
    temp[h]=R[h];
    if((X[h]|Y[h])==0)temp[h]=0;
  // cout<<temp<<"\n";
  }
  calc_cost(temp,-1);
}
void solve(){
  cin>>x>>y>>l>>r;mi=0;h=zz=0;
  if(x==0 or r==0 or y==0){cout<<0;return;}
  h=log2(r)+1;
  X=bitset<70>(x);
  Y=bitset<70>(y);
  R=bitset<70>(r);
  string fk(h,'1');
  final=bitset<70>(fk);
  // cout<<final;
  f();
  // cout<<final;
  // cout<<fk;
  if (final.to_ullong()>r)
  {
      cout<<0;return;
  }
  cout<<final.to_ullong();
}
int32_t main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;
  while(t--){solve();cout<<"\n";}
  return 0;
}
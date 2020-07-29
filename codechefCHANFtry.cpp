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
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int x,y,l,r,h,zz;int mi=-inf;
bitset<70>X,Y,R,final;
void calc_cost(bitset<70>z,int n){
  int cos=0;
  // if(n+1>=0)z[n+1]=0;
  if(n==-1)return;
  for (int i = n; i > -1; --i)
  {
    z[i]=X[i]|Y[i];
  }
  // cout<<n<<" "<<z<<"\n";
  zz=z.to_ullong();
  if(zz>r)return;
  cos=(zz&x)*(zz&y);
  // cout<<cos<<"\n";
  if(cos>=mi){
    mi=cos;
    if(cos==mi)if(z.to_ullong()<final.to_ullong())final=z;
    else final=z;
  }
}
bool ok=0;
bitset<70>z;
void f(int i){
  if(i==-1){
    calc_cost(z,-2);
    return;
  }
  if((R[i]==1) or ok==1)calc_cost(z,i-1);
  if(X[i]|Y[i]==1)z[i]=R[i];
  else z[i]=0;
  if(z[i]==0 and R[i]==1)ok=1;
  f(i-1);
  // z[i]=R[i]^1;
  // f(i-1);
}
void solve(){
  ok=0;
  cin>>x>>y>>l>>r;mi=-inf;h=zz=0;
  if(x==0 or r==0 or y==0){cout<<0;return;}
  h=log2(r);
  // cout<<"\n\n"<<h<<"\n\n";
  X=bitset<70>(x);
  Y=bitset<70>(y);
  R=bitset<70>(r);
  // if(R[h]==1){
    calc_cost(R,-2);
  // }
  string fk(64,'1');
  z=bitset<70>(0);
  final=bitset<70>(fk);
  f(h);
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
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
// #include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e1+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int a[N],n;
int f(int pos,int l=-1){
  if(pos==0 or pos==n+1 or a[pos]==inf)return 0;
  int R=0,L=0;
  if(l==-1){
    R=L=0;
    if(a[pos+1]<=2+a[pos])R=f(pos+1,1);
    if(a[pos-1]+2>=a[pos])L=f(pos-1,0);
    return 1+L+R;
  }
  if(l==1 and a[pos+1]<=2+a[pos])return 1+f(pos+1,1);
  if(l==0 and a[pos-1]+2>=a[pos])return 1+f(pos-1,0);
  return 1;
}
void solve(){
  memset(a,inf,sizeof(a));
  cin>>n;for(int i=1;i<=n;i++)cin>>a[i];
  int mi=1e9,ma=-1e9;
  for (int i = 1; i <= n; ++i)
  {
    int x=f(i);
    mi=min(mi,x),ma=max(ma,x);
  }
  cout<<mi<<" "<<ma;
}
int main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;
  while(t--){solve();cout<<"\n";}
  return 0;
}
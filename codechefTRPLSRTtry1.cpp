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
const int N=2e5+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int a[N],b[N],x[N],y[N],z[N];
void solve(){
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++){cin>>a[i];b[a[i]]=i;}
  int c=0;
  for (int i = 1; i <= n; i+=1)
  {
    if(i!=a[i]){
      x[c]=i;y[c]=a[i];z[c]=b[i];
      int A=x[c],B=y[c],C=z[c];
      swap(a[x[c]],a[z[c]]),swap(a[z[c]],a[y[c]]);
      swap(b[x[c]],b[y[c]]),swap(b[z[c]],b[y[c]]);
      // for(int i=1;i<=n;i++){b[a[i]]=i;}
      // b[z[c]]=x[c],b[a[y[c]]]=z[c],b[a[x[c]]]=y[c];
      c++;
  //      for (int i =1; i <= n; ++i)
  // {
  //   cout<<b[i];
  // }
  // cout<<"\n";
    }
  }
  // cout<<c;
  // for (int i =1; i <= n; ++i)
  // {
  //   cout<<a[i];
  // }
  // cout<<"\n";
  // for (int i =1; i <= n; ++i)
  // {
  //   cout<<b[i];
  // }
  for (int i = 0; i < c; ++i)
  {
    if(x[i]==y[i] or y[i]==z[i] or x[i]==z[i]){cout<<-1;return;}
  }
  if(is_sorted(a+1,a+1+n) and c<=k)
  cout<<c<<"\n";
  else {cout<<-1;return;}
  for (int i = 0; i < c; ++i)
  {
    cout<<x[i]<<" "<<y[i]<<" "<<z[i]<<"\n";
  }
}
int main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;
  while(t--){solve();cout<<"\n";}
  return 0;
}
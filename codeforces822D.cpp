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
const int N=5e6+4;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int t,l,r,F[N],ans,p=1;
void f(){
  for(int i=1;i<=r;i++){
    F[i]=i*(i-1)/2;
  }
  for(int i=1;i<=r;i++)
    for(int j=1;i*j<=r;j++)
      F[i*j]=min(F[i*j],F[i]+i*F[j]);
}
int mul(int a,int b){
  return ((a%M)*(b%M))%M;
}
int add(int a,int b){
  return ((a%M)+(b%M))%M;
}
void solve(){
  cin>>t>>l>>r;
  f();
  for(int i=l;i<=r;i++){
    ans=add(ans,mul(F[i],p));
    p=mul(p,t);
  }
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // int x=0;
  // while(t--){solve();cout<<"\n";}
  return 0;
}
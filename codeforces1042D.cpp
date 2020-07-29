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
int n,t,a[N],B[N],p[N],sum,num;
void merge(int l,int mid,int r){
    for (int i=l; i<mid; i++){
      B[i]=p[i];
  }
  B[mid]=inf;
  for (int i=mid; i<r; i++){
      B[i+1]=p[i];
  }
  B[r+1]=inf;
  int i=l, j=mid+1;
    for (int k=l; k<r; k++){
    if (B[i]<=B[j]) p[k]=B[i++];
    else p[k]=B[j++];
    }
}
void m(int l,int r){
  if(r-l<2)return;
  int M=l+r+1>>1;
  m(l,M);
  m(M,r);
  for(int i=l;i<M;i++){
    num+=(lower_bound(p+M,p+r,p[i]+t)-(p+M));
  }
  merge(l,M,r);
}
void solve(){
  cin>>n>>t;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];
  m(0,n+1);
  // for(int i=1;i<=n;i++){
  //   sum-=a[i-1];if(sum<t)num++;
  //   while(sum<t and j<n)sum+=a[j+1],j++,num++;
  // }
  cout<<num;
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
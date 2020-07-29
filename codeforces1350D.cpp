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
#include <bits/stdc++.h>
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,k,i,j,l,r,a[N];
void solve(){
  cin>>n>>k;
  vector<int> v;map<int,int>m;
  a[n+1]=a[n+2]=-1;
  for(int i=1;i<=n;i++){cin>>a[i];if(a[i]==k)v.pb(i);}
    if(n==1){if(a[1]==k)cout<<"yes";else cout<<"no";return;}
  if(v.empty())cout<<"no";
  else{
  for(int i=1;i<=n;i++){
    if(a[i]>=k and a[i+1]>=k){
      cout<<"yes";return;
    }
    if(a[i]>=k and a[i+2]>=k){
      cout<<"yes";return;
    }
  }
  cout<<"no";
}
}
int32_t main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;
  // int x=0;
  while(t--){solve();cout<<"\n";}
  return 0;
}
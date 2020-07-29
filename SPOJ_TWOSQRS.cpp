#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <numeric>
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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e9;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,a[N];set<int>s;
void solve(){
  cin>>n;
  // if(((n-1)%4) == 0){cout<<"Yes";return;}
  int l=0,r=sqrt(n);
  while(l<=r){
    int num=a[l]+a[r];
    if(num==n){cout<<"Yes";return;}
    if(num>n)r--;
    else l++;
  }
  // if(a[l]+a[r]==n){cout<<"Yes";return;};
  cout<<"No";
}
int32_t main()
{
  ibs;cti;
  for(int i=0;i<=1e6;i++){
    a[i]=i*i;
  }
  // solve()
  /*,cout<<"\n"*/;
  int x=0;
  int t;cin>>t;while(t--){/*x++;cout<<"Case #"<<x<<": ";*/solve();cout<<"\n";}
  return 0;
}
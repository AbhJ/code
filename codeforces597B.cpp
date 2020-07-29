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
const int N=5e5+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
bool cmp(pair<int,int>a,pair<int,int>b){
  return a.S<b.S;
}
int n,c=1,l=1;pair<int,int>a[N];
void solve(){
  cin>>n;for(int i=1;i<=n;i++)cin>>a[i].F>>a[i].S;
  sort(a+1,a+1+n,cmp);
  for (int i = 2; i <=  n; ++i)
    if(a[i].F>a[l].S)c++,l=i;
  cout<<c;
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}
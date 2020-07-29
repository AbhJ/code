#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
// #include <numeric>
#include <vector>
// #include <iterator> 
// #include <map>
#include <set>
// #include <climits>
// #include <queue>
// #include <iomanip>
// #include <cmath>
// #include <stack>
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
int a[N];int dp[2][N];int w,m;
bool f(int n=m){
  if(n==1 or n==0)return 1;
  if((n+1)%w==0 and f((n+1)/w)==1)return 1;//add 1 in same plate
  if((n)%w==0 and f((n)/w)==1)return 1;
  if((n-1)%w==0 and f((n-1)/w)==1)return 1;//add 1 in other plate
  return 0;
}
void solve(){
  cin>>w>>m;
  if(f())cout<<"YES";
  else cout<<"NO";
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}
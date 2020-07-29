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
const int N=4e5+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,k,a[N],b[N],c[N],ans=1e9;
void solve(){
  cin>>n>>k;memset(b,0,sizeof(b));memset(c,0,sizeof(c));ans=1e9;
  for (int i = 1; i <= n; ++i)cin>>a[i];
  for (int i = 1; i <= n/2 ; ++i)b[min(a[i],a[n-i+1])+1]++,b[max(a[i],a[n-i+1])+k+1]--,c[a[i]+a[n-i+1]]++;
  for (int i = 2; i <= 2*k; ++i)//min sum =2 and max sum=2*k+1
    b[i]+=b[i-1],
    ans=max(0,min(ans,(b[i]-c[i])+(n/2-b[i])*2));//in n/2-b[i] pairs both to be changed
  //in b[i]-c[i] pair one to be changed
  cout<<ans;
}
int main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;
  while(t--){solve();cout<<"\n";}
  return 0;
}
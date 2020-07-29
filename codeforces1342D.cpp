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
int a[N],c[N],ans,g;map<int,int>m;
void solve(){
  int n,k;cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i],m[a[i]]++;
  for(int i=1;i<=k;i++)cin>>c[i];
  for(int i=k;i>=1;i--){
    g+=m[i];
    ans=max(ans,(g+c[i]-1)/c[i]);
  }
  cout<<ans;
  sort(a+1,a+n+1);
  vector<int> v[ans];
  for(int i=1;i<=n;i++)v[i%ans].pb(a[i]);
  for(int i=0;i<ans;i++){
    cout<<"\n"<<v[i].size()<<" ";
    for(auto j:v[i])cout<<j<<" ";
  }
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}
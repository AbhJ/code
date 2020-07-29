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
const int N=1e5+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,q,c;string s;int m[N],a[N];
void solve(){
  cin>>n>>q>>s;
  memset(m,0,sizeof(m));
  memset(a,0,sizeof(a));
  for (int i = 0; i < n; ++i)
  {
    m[s[i]]++;
  }
  // for (int j = 'a'; j <= 'z'; ++j)cout<<(char)j<<m[j]<<"\n";
  // for (int i = 2; i <= n+2; ++i)
  // {
  //   for (int j = 'a'; j <= 'z'; ++j)
  //    if(m[j]>=i)a[i]+=m[j]-1;
  //   // cout<<a[i]<<" ";
  // }
  while(q--){
    cin>>c;
    int ans=0;
    for (int i = 'a'; i <= 'z'; ++i)
    {
      if(m[i]>c)ans+=m[i]-c;
    }
    cout<<ans<<"\n";
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
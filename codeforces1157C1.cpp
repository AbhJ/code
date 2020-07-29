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
string s;int n,L=-1,a[N];
void f(int l=1,int r=n){
  if(a[l]<L and a[r]<L)return;
  if(l>r)return;
  if(a[l]>L and a[r]>L){
    if(a[l]<=a[r])s+='L',L=a[l],f(l+1,r);
    else s+='R',L=a[r],f(l,r-1);
    return;
  }
  if(a[l]>L)s+='L',L=a[l],f(l+1,r);
  else s+='R',L=a[r],f(l,r-1);
}
void solve(){
  cin>>n;
  for (int i = 1; i <= n; ++i)cin>>a[i];
  f();
  cout<<s.length()<<"\n"+s+"\n";
}
int main()
{
  ibs;cti;
  solve()/*,cout<<"\n"*/;
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}
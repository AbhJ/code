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
const int N=2e5+1;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
set<int>s;int n,a;
void f(){
   for(auto i:s)cout<<i<<" ";cout<<"\n";exit(0);
}
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a;
    s.insert(a);
  }
  while(1){
    int val=*s.rbegin(),V=*s.rbegin();
    // cout<<val<<" ";
    s.erase(val);
    while(1){
      val/=2;
      if(val==0)s.insert(V),f();
      if(s.count(val)==0)break;
    }
    s.insert(val);
    // cout<<val<<"\n";
    // if(val==V)break;
  }
}
int32_t main()
{
  ibs;cti;
  solve(),cout<<"\n";
  int x=0;
  // int t;cin>>t;while(t--){/*x++;cout<<"Case #"<<x<<": ";*/solve();cout<<"\n";}
  return 0;
}
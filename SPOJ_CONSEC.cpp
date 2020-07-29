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
#include <bits/stdc++.h>
// #define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1<<30;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
string s;int l,r,n,q,x,i;//starting, ending
void solve(){
  cin>>s>>q;set<pair<int,int>>S;
  l=0;n=s.size();
  for(i=1;i<n;i++)
    if(s[i]!=s[l]){
      S.insert({l,i-1});
      l=i;
    }
  S.insert({l,n-1});
  while(q--){
    cin>>x>>i;
    auto it= --(S.upper_bound({i,inf}));
    l=(*it).F;r=(*it).S;
    if(x==1){
      cout<<r-l+1<<"\n";
    }
    else{
      S.erase(it);
      if(l!=i)S.insert({l,i-1});
      if(r!=i)S.insert({i+1,r});
    }
  }
}
int32_t main()
{
  ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  int xx=0;
  int t;cin>>t;while(t--){xx++;cout<<"Case "<<xx<<":\n";solve();/*cout<<"\n";*/}
  return 0;
}
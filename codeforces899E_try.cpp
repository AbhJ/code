//Coded by Abhijay Mitra
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
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e9+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int a[N],n,ans;set<pair<int,int>>s,S1,S2;
void solve(){
  cin>>n;int j=1,cur=0;
  for(int i=1;i<=n+1;i++){
    if(i<=n)cin>>a[i];
    if(a[i]!=cur and i>1)s.insert({i-j,j}),S1.insert({j,i-1}),S2.insert({i-1,j}),j=i,cur=a[i];
    if(cur==0)cur=a[i];
  }
  //S1 st en
  //S2 en st
  // for(int i=1;i<=n;){
  //   int l=i;
  //   while(a[i]==a[i+1])i++;
  //   if(l!=i)s.push({i-l,{l,i-1}});
  //   else i++;
  // }
  // while(s.empty()==0){
  //   cout<<s.top().S.F<<s.top().S.S<<"\n";
  //   s.pop();
  // }
  while(s.empty()==0){
    ans++;
    int len=(*s.rbegin()).F,l=(*s.rbegin()).S;
    int r=l+len-1;
    cout<<l<<" "<<r<<" "<<len<<"\n";
    // s.erase(prev(s.end()));
    s.erase({len,l});
    S1.erase({l,r});
    S2.erase({r,l});
    if(S2.lower_bound({l-1,1})!=S2.end() and S1.lower_bound({r+1,1})!=S1.end()){
      int R=(*S1.lower_bound({r+1,1})).S;
      int L=(*S2.lower_bound({l-1,1})).S;
      // cout<<L<<" "<<R<<"\n";
      S1.erase({r+1,R});
      S2.erase({R,r+1});
      s.erase({R-r,r+1});
      if(a[l-1]==a[r+1]){
        s.insert({R-L-r+l,L});
        // cout<<R-L-r+l<<"\n";
        S1.insert({L,R-r+l-L+L-1});
        S2.insert({L+R-L-r+l-1,L});
        S1.erase({L,l-1});
        S2.erase({l-1,L}); 
        s.erase({l-L,L});
      }
      else{
        s.insert({R-r,l});
        S1.insert({l,l+R-r+1});
        S2.insert({l+R-r+1,l});
      }
    }
    else if(S2.lower_bound({l-1,1})==S2.end()){
      int R=(*S1.lower_bound({r+1,1})).S;
      S1.erase({r+1,R});
      S2.erase({R,r+1});
      s.erase({R-r,r+1});
      // if(a[R]==a[L]){
      //   s.insert({R-L-r+l,L});
      //   S1.insert({L,L+R-L-r+l-1});
      //   S2.insert({L+R-L-r+l-1,L});
      //   S1.erase({L,l-1});
      //   S2.erase({l-1,L}); 
      //   s.erase({l-L,L});
      // }
       // else{
        s.insert({R-r,l});
        S1.insert({l,l+R-r+1});
        S2.insert({l+R-r+1,l});
      // }
    }
    else if(S1.lower_bound({r+1,1})==S1.end()){
      int L=(*S2.lower_bound({l-1,1})).F;
    }
    else{
      break;
    }
    // cout<<s.top().S.F<<s.top().S.S<<"\n";
  }
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();/*cout<<"\n";*/}
  return 0;
}
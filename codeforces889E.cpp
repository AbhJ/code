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
// #define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e9+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int a[N],n,ans;set<pair<int,int>>s,S;
void solve(){
  cin>>n;int j=1,cur=0;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n+1;i++){
    if(a[i]!=cur and i>1)s.insert({-(i-j),j}),S.insert({j,i-j}),j=i,cur=a[i];
    if(cur==0)cur=a[i];
  }
  while(s.empty()==0){
    ans++;auto X=s.begin();
    int len=-(*X).F,l=(*X).S;
    s.erase(X);
    S.erase({l,len});
    auto i=S.lower_bound({l,len}),j=S.upper_bound({l,len});
    if(i!=S.end() and j!=S.begin()){
      j--;
      auto x=*i,y=*j;
      //y is the segment on the left
      //x is the segment on the right
      if(a[x.F]==a[y.F]){
        S.erase(i),S.erase(j);
        int length=x.S+y.S;
        S.insert({y.F,length});
        s.erase(s.find({-(x.S),x.F}));
        s.erase(s.find({-(y.S),y.F}));
        s.insert({-length,y.F});
      }
    }
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
//Coded by Abhijay Mitra
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
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
#define res(vector) v.resize(unique(v.begin(), v.end()) - v.begin());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e9+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,x,ans,l[N],r[N],j,a[N];stack<int>s;map<int,vector<int>>p;
int sum(int t[],int l, int r,int v=1, int tl=0, int tr=n-1 ) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return sum( t,l, min(r, tm),v*2, tl, tm)
           + sum(t,max(l, tm+1), r,v*2+1, tm+1, tr );
}
//
void update(int t[],int pos, int new_val,int v=1, int tl=0, int tr=n-1 ) {
    if (tl == tr) {
        t[v] += new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(t,pos,new_val,v*2, tl, tm);
        else
            update(t,pos,new_val,v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
//basically we need distance b/w pairs i,j such that v[j]<=v[i]
//and a[j]<a[i]
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)p[a[i]].pb(i);
  for(int i=1;i<=n;i++){
    while(s.empty()==0 and a[s.top()]<a[i])s.pop();
    if(s.empty()==0)l[i]=s.top();
    s.push(i);
  }
  s=stack<int>();
  for(int i=n;i>=1;i--){
    while(s.empty()==0 and a[s.top()]<a[i])s.pop();
    if(s.empty()==0)r[i]=s.top();
    else r[i]=n+1;
    s.push(i);
  }
  for(int i=1;i<=n;i++)++l[i],--r[i];
  //l[i] is leftmost element till which a[i] is max
  //r[i] is rightmost element till which a[i] is max
  for(int i=1;i<=n;i++){
    if(i-l[i]<r[i]-i){
      for(j=l[i];j<i;j++){
        if(p.count(a[i]-a[j])==0)continue;
        for(auto suspect:p[a[i]-a[j]])
          if(suspect<=r[i] and suspect>=i)ans++;
      }
    }
    else{
      for(j=r[i];j>i;j--){
        if(p.count(a[i]-a[j])==0)continue;
        for(auto suspect:p[a[i]-a[j]])
          if(suspect>=l[i] and suspect<=i)ans++;
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
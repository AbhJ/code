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
int n,k,l,m,r,q,best,ok,fuck=-1,a[N];set<int>s[N];
void f(){
  int c=0;
  for(int i=1;i<=n;i++)
    if(a[i]!=l)
      c++;
  if(c!=0)
  {cout.flush();
    cout<<"? "<<c<<" ";
    cout.flush();
    for(int i=1;i<=n;i++)
      if(a[i]!=l)
        cout<<i<<" ";
    cout<<"\n";
    cout.flush();
    cin>>ok;}
  cout<<"! ";
  cout.flush();
  for(int i=1;i<=k;i++){
    if(i!=l)cout<<best<<" ";
    else cout<<ok<<" ";
  }
  cout.flush();
  string f;cin>>f;
  if(f[0]=='I')cout<<"bitch",exit(0);
  cout.flush();
}
int h(int l,int r){
  int c=0;
  for(int i=1;i<=n;i++)
    if(a[i]>=l and a[i]<=r)
      c++;
  if(c==0)return -1;
  cout.flush();
  cout<<"? "<<c<<" ";
  cout.flush();
  for(int i=1;i<=n;i++)
    if(a[i]>=l and a[i]<=r)
      cout<<i<<" ";
  cout<<"\n";
  cout.flush();
  cin>>q;
  return q;
}
void solve(){
  cin>>n>>k;ok=-1;
  for(int i=1;i<=n;i++)a[i]=0;
  for(int i=1;i<=k;i++){
    int x,y;cin>>x;
    while(x--)cin>>y,a[y]=i;
  }
  l=0;r=k;best=h(l,r);fuck=-1;
  while(l<r){
    m=l+r>>1;
    if(h(l,m)==best){r=m;}
    else l=m+1,fuck=l;
  }
  if(fuck==-1)fuck=l;
  f();
}
int32_t main()
{
  // ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";
  /*timer;*/}
  return 0;
}
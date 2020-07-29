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
const int N=5e5+1;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,m,p,pos[N],l[N],r[N];string s,q;
void solve(){
  memset(pos,-1,sizeof pos);
  cin>>n>>m>>p>>s>>q;s='#'+s;
  stack<int>st;
  for(int i=1;i<=n;i++){
    if(s[i]=='(')st.push(i);
    else{
      int x=st.top();
      st.pop();
      pos[x]=i;
      pos[i]=x;
    }
  }
  for(int i=1;i<=n;i++)l[i]=i-1,r[i]=i+1;
  r[0]=1,l[n+1]=n;
  // for(auto [i,j]:S)cout<<i<<" "<<j<<"\n";
  for(int i=0;i<m;i++){
    char o=q[i];
    if(o=='D'){
      int L=p,R=pos[p];
      if(L>R)swap(L,R);
      l[r[R]]=l[L];
      r[l[L]]=r[R];
      p=r[R];
    }
    if(o=='R')p=r[p];
    if(o=='L')p=l[p];
    if(p>n)p=l[p];
    if(p<1)p=r[0];
  }
  while(l[p])p=l[p];
  for(int i=p;i<=n;i=r[i]){
    cout<<s[i];
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
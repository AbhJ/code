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
#include <bitset>
// #include <bits/stdc++.h>
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e3+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n;
queue<int>q;vector<int>p(10);string Q,P;
void done(){
  // cout<<"F";
  for(int i=9;i>=0;i--)
    for(int j=0;j<p[i];j++)
      cout<<i;
  exit(0);
}
void solve(){
  cin>>P>>Q;
  for(auto x:P)p[x-'0']++;
  for(auto x:Q)q.push(x-'0');
  n=P.length();
  if(Q.length()>n)done();
  while(q.size()){
    int r=q.front();q.pop();
    for(int i=9;i>=0;i--){
      if(i==r and p[i]>0){
        cout<<i;p[i]--;break;
      }
      if(i<=r and p[i]>0){
        cout<<i;p[i]--;done();
      }
    }
  }
}
int32_t main()
{
  // ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // int x=0;
  // while(t--){solve();cout<<"\n";}
  return 0;
}
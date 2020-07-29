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
const int N=2e5+4;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,k,i,j,on,mi;string s;
void solve(){
  cin>>n>>k>>s;on=0;mi=inf;
  for(auto I:s)if(I=='1')on++;mi=on;
  for(int i=0;i<k;i++){
    int minus=0;
    for(int j=i;j<n;j+=k){
      if(s[j]=='1')minus++;
      else minus--;
      minus=max(minus,0LL);
      mi=min(on-minus,mi);
    }
  }
  cout<<mi;
}
int32_t main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;while(t--){solve();cout<<"\n";}
  // int x=0;
  return 0;
}
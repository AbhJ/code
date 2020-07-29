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
#define ll long long int8_t
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=5e5+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,i,k;
void solve(){
  cin>>n>>k;i=0;
  while(++i<k){
    int num=n,mi=1e9,ma=0;
    while(num){
      mi=min(mi,num%10);
      ma=max(ma,num%10);
      num/=10;
    }
    if(mi==0)break;
    n+=mi*ma;
  }
  cout<<n;
}
int32_t main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;while(t--){solve();cout<<"\n";}
  // int x=0;
  return 0;
}
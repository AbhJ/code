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
#define double long double
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
double a[N],b[N];map<double,int>ma;int x,n;
void solve(){
  cin>>n;
  for (int i = 0; i < n; ++i)
  {
    cin>>a[i];
  }
  int check=0,c=0;
  for (int i = 0; i < n; ++i)
  {
    cin>>b[i];
    if(b[i]==0 and a[i]==0){
      check++;continue;
    }
    if(a[i]==0)continue;
    x=max(x,++ma[b[i]/a[i]]);
  }
  cout<<x+check;
}
int32_t main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // int x=0;
  // while(t--){solve();cout<<"\n";}
  return 0;
}
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
const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,a[N];
void solve(){
  cin>>n;
  if(n<4){cout<<-1;return;}
  for(int i=0;i<n/5;i++){
    int j=i*5;
    a[j]=j+3;
    a[j+1]=j+1;
    a[j+2]=j+5;
    a[j+3]=j+2;
    a[j+4]=j+4;
  }
  if(n==4){cout<<"3 1 4 2";return;}
  set<int>s;int l=0;
  int i;
  for (i = 0; i < (n/5)*5; ++i)
  {
    s.insert(a[i]);l=a[i];
  }
  if(n%5==1)a[n-1]=n;
  else if(n%5==2)a[n-1]=n,a[n-2]=n-3,a[n-3]=n-1;
  else if(n%5==3)a[n-1]=n-1,a[n-2]=n-4,a[n-3]=n,a[n-4]=n-2;
  else if(n%5==4)a[n-1]=n-2,a[n-2]=n,a[n-3]=n-3,a[n-4]=n-1;
  for (i = 0; i < n; ++i)
  {
    cout<<a[i]<<" ";
  }
}
int32_t main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;
  while(t--){solve();cout<<"\n";}
  return 0;
}
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
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,a[2*N],b[2*N],p[2*N];
void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
    b[a[i]]++;
  }
  for(int i=1;i<2*N;i++){
    p[i]=p[i-1]+b[i];
  }
  int ans=0;
  for(int i=1;i<N;i++){
    if(b[i]==0)continue;
    int ma=0;
    for(int j=i;j+1-1<N;j+=i)
      ma+=j*(p[i+j-1]-p[j-1]/*+b[j]*/);//how many times j appears
    //between i+j-1 and j both inclusive
    ans=max(ans,ma);
  }
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  solve()/*,cout<<"\n"*/;
  int x=0;
  // int t;cin>>t;while(t--){/*x++;cout<<"Case #"<<x<<": ";*/solve();cout<<"\n";}
  return 0;
}
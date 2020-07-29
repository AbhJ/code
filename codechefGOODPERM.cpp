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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e9;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,k,a[N],ans,b[N];set<int>s;
void solve(){
  cin>>n>>k;ans=0;
  for(int i=1;i<=n;i++)cin>>a[i],b[i]=i;
  do{
    bool fail=0;
    int K=0;
    for(int i=1;i<=n;i++){
      if(a[i]!=0 and a[i]!=b[i])fail=1;
      if(i>=2 and b[i]>b[i-1])K++;
    }
    if(fail==1)continue;
    if(k==K)ans++;
  }while(next_permutation(b+1,b+1+n)!=0);
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  int x=0;
  int t;cin>>t;while(t--){/*x++;cout<<"Case #"<<x<<": ";*/solve();cout<<"\n";}
  return 0;
}
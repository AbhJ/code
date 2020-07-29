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
// #define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*//*1e15*/1e9;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,a[N],ans,b[N],appear[N];
void solve(){
  cin>>n>>a[0];
  for(int i=1;i<=n;i++){
    cin>>a[i];
    b[a[i]]=i;
    //b[i] stores the last occurence of i
  }
  for(int i=1;i<=n;i++){
    int r_most=b[a[i]],most_used=0;
    for(int j=i;j<=r_most;j++){
      r_most=max(r_most,b[a[j]]);
      most_used=max(most_used,++appear[a[j]]);
    }
    ans+=r_most-i+1-most_used;
    i=r_most;
    //the number of elements we change in
    //a block like 3733777737733777733333
    // in the block 66663733777737733777733333555555
  }
  cout<<max(0,ans);
}
int32_t main()
{
  ibs;cti;
  solve()/*,cout<<"\n"*/;
  int x=0;
  // int t;cin>>t;while(t--){/*x++;cout<<"Case #"<<x<<": ";*/solve();cout<<"\n";}
  return 0;
}
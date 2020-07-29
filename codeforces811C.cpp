#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
// #include <numeric>
#include <vector>
// #include <iterator> 
// #include <map>
// #include <set>
// #include <climits>
// #include <queue>
// #include <iomanip>
// #include <cmath>
// #include <stack>
#include <cctype>
// #include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=5e3+10;
const int inf = 0x3f3f3f3f;
const ll M = 998244353 ; // Mulo
// const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
bool b[N];
int a[N],l[N],r[N],dp[N];//l[i] is leftmost occurence of i and r[i] is rightmost
void solve(){
  int n;cin>>n;
  for (int i = 1; i <= n; ++i){
    cin>>a[i];
    if(l[a[i]]==0)l[a[i]]=i;
    r[a[i]]=i;
  }
  for(int i=1;i<=n;i++){
    int x=0,L=l[a[i]];dp[i]=dp[i-1];
    memset(b,0,sizeof(b));
    for(int j=i;j>=1;j--){
      if(r[a[j]]>i)//some element will be left if we choose i to j segment
        break;
      if(b[(a[j])]==0)x^=a[j],b[(a[j])]=1;//we want xor of distinct elements
      if(j<=(L=min(L,l[a[j]])))dp[i]=max(dp[i],dp[j-1]+x);
    }
  }
  cout<<dp[n];
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}
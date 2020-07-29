#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
// #include <numeric>
#include <vector>
// #include <iterator> 
// #include <map>
#include <set>
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
const int N=1e2+10;
const int inf = 0x3f3f3f3f;
const ll M = 998244353 ; // Mulo
// const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
string s[N];int dp1[N],dp2[N],A[N],B[N];
void solve(){
  int n,m;cin>>n>>m;
  string t="";
  for(int i=1;i<=m+2;i++)t+='0';
  for (int i = n; i >= 1; --i)cin>>s[i];
  while(s[n]==t)n--;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)if(s[i][j]=='1'){if(B[i]==0)B[i]=m-j+1;A[i]=j;}
  dp1[n]=A[n];dp2[n]=B[n];
  for(int i=n-1;i>=1;i--){
    if(A[i]==B[i] and A[i]==0){dp1[i]=min(dp1[i+1],dp2[i+1]+m+1)+1;dp2[i]=min(dp1[i+1]+m+1,dp2[i+1])+1;continue;}
    dp1[i]=min(2*A[i]+dp1[i+1],m+1+dp2[i+1])+1;
    dp2[i]=min(2*B[i]+dp2[i+1],m+1+dp1[i+1])+1;
  }
  cout<<dp1[1];
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}
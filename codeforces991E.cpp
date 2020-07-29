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
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/ 1e18+12;
// const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int cnt[N],t[N],fact[N],ans,sum,z,prod;
int fact_dp(int n)

{

    if (n >= 0) 

    {

        fact[0] = 1;

        for (int i = 1; i <= n; ++i) 

        {

            fact[i] = i * fact[i - 1];

        }

        return fact[n];

    }

}
void solver(){
  z=0,sum=0,prod=1;
  for (int i = 0; i < 10; ++i)
  {
    sum+=t[i];prod*=fact[t[i]];
  }
  z=fact[sum]/prod;
  if(t[0]!=0)z-=t[0]*z/sum;
  ans+=z;
}
void f(int x=0){
  if(x==10){solver();return;}
  if(cnt[x]==0)f(x+1);
  for(int i=1;i<=cnt[x];i++)t[x]=i,f(x+1);
  // cout<<cnt[0];
}
int n,a,b;string s;
void solve(){
  cin>>s;
  for(auto i:s)cnt[i-'0']++;
  fact_dp(19);
  // cout<<fact[18];
  f();
  cout<<ans;
}
int32_t main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}
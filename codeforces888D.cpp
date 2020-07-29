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
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,m,ans=1,der[N];
int powM(int,int);
long long C(long long n,long long r)
{
    long long N=1,R=1;
    for(long long i=1;i<=n;i++) N=N*i%M;
    for(long long i=1;i<=r;i++) R=R*i%M;
    for(long long i=1;i<=n-r;i++) R=R*i%M;
    return (N*powM(R,M-2))%M;
}
int binomialCoeffUtil(int n, int k, int** dp) 
{ 
    // If value in lookup table then return 
    if (dp[n][k] != -1) //      
        return dp[n][k]; 
  
    // store value in a table before return 
    if (k == 0) { 
        dp[n][k] = 1; 
        return dp[n][k]; 
    } 
      
    // store value in table before return 
    if (k == n) { 
        dp[n][k] = 1;  
        return dp[n][k]; 
    } 
      
    // save value in lookup table before return 
    dp[n][k] = binomialCoeffUtil(n - 1, k - 1, dp) + 
               binomialCoeffUtil(n - 1, k, dp); 
    return dp[n][k]; 
} 
  
int binomialCoeff(int n, int k) 
{ 
    int** dp; // make a temporary lookup table 
    dp = new int*[n + 1]; 
  
    // loop to create table dynamically 
    for (int i = 0; i < (n + 1); i++) { 
        dp[i] = new int[k + 1]; 
    } 
  
    // nested loop to initialise the table with -1 
    for (int i = 0; i < (n + 1); i++) { 
        for (int j = 0; j < (k + 1); j++) { 
            dp[i][j] = -1; 
        } 
    } 
  
    return binomialCoeffUtil(n, k, dp); 
} 
int powM(int b, int p) {
  int r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
int countDer(int n) 
{ 
    // Create an array to store  
    // counts for subproblems  
  
    // Base cases 
    der[0] = 1; 
    der[1] = 0; 
    der[2] = 1; 
  
    // Fill der[0..n] in bottom up manner  
    // using above recursive formula 
    for (int i = 3; i <= n; ++i) 
        der[i] = (i - 1) * (der[i - 1] +  
                            der[i - 2]); 
  
    // Return result for n 
    return der[n]; 
}
void solve(){
  cin>>n>>m;countDer(1000);
  int tol=m;
  for(int tol=1;tol<=m;tol++){
    ans+=binomialCoeff(n,tol)*(der[tol]);
  }
  cout<<ans;
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
//Coded by Abhijay Mitra
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
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
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
#define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
#define cnt_res(v) std::distance(v.begin(),std::unique(v.begin(), v.end())); 
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int mul(int a,int b){
  return ((a%M)*(b%M))%M;
}
int add(int a,int b){
  return ((a%M)+(b%M))%M;
}
ll gcdExtended(ll a, ll b, ll *x, ll *y); 
  
// Function to find modulo inverse of b. It returns 
// -1 when inverse doesn't 
ll modInverse(ll b, ll m) 
{ 
    ll x, y; // used in extended GCD algorithm 
    ll g = gcdExtended(b, m, &x, &y); 
  
    // Return -1 if b and m are not co-prime 
    if (g != 1) 
        return -1; 
  
    // m is added to handle negative x 
    return (x%m + m) % m; 
} 
  
// Function to compute a/b under modlo m 
ll div(ll a, ll b, ll m=M) 
{ 
    a = a % m; 
    ll inv = modInverse(b, m); 
    // if (inv == -1) 
    //    cout << "Division not defined"; 
    // else
       return (inv * a) % m; 
} 
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
// C function for extended Euclidean Algorithm (used to 
// find modular inverse. 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}
int f(int a,int b,int c){
  //this function computes a*(b^c)
  if(b==1)return a;
  int ans=a;
  if(c-2>((double)log(1e6+5)/log(b)))return -1;
  int x=pow(b,c);
  if(x>0 and x<1e6+10)ans*=x;
  else return -1;
  if(ans>0 and ans<1e6+10)return ans;
  return -1;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
int n,p;
void solve(){
  //idea is based on algopedia's video for #647
  map<int,int>m;
  cin>>n>>p;std::vector<int> k(n);
  for(int i=0;i<n;i++){cin>>k[i];m[k[i]]++;}
  sort(k.begin(), k.end());
  reverse(k.begin(), k.end());
  res(k);
  n=cnt_res(k);
  int j=0,i,d=0;
  while(j<n){
    if((m[k[j]]&1)==0){
      j++;continue;
    }
    int cnt=1,x=k[j],ok=0;
    for(i=j+1;i<n;i++){
      int n_cnt=f(cnt,p,x-k[i]);
      if(n_cnt==-1)break;
      if(n_cnt<=m[k[i]]){
        //we can satisfy all needs
        m[k[i]]-=n_cnt;
        j=i;
        ok=1;
        break;
      }
      else{
        cnt=n_cnt-m[k[i]];
        x=k[i];
      }
    }
    if(ok==0){
      d=powM(p,k[j]);
      for(i=j+1;i<n;i++)
        d=sub(d,mul(m[k[i]],powM(p,k[i])));
      break;
    }
  }
  cout<<d;
}
int32_t main()
{
  ibs;cti;
  // solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
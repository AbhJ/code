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
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int sp[(int)1e7+1LL];
bool v[(int)1e7+1LL];
// void gen_primes() {
//   int i,j;
//   for(i=0;i<1e7+1;i++) p[i] = 1;
//   for(i=2;i<=(int)sqrt(1e7+1);i++)
//   if (p[i])
//   for(j=i;j*i<1e7+1;j++) p[i*j] = 0;
// }
void Sieve(){
  for (int i = 2; i < 1e7+1; i += 2)  sp[i] = 2;//even numbers have smallest prime factor 2
  for (int  i = 3; i < 1e7+1; i += 2){
    if (!v[i]){
      sp[i] = i;
      for (int j = i; (j*i) < 1e7+1; j += 2){
        if (!v[j*i])  v[j*i] = true, sp[j*i] = i;
      }
    }
  }
}

map<int,vi>m;
vector<int> fact(int n)
{
    vector<int> v;
    for(int i=2;i<=sqrt(n);++i)
    {
        if(v.size()>=4)break;
        if(n%i==0)
        {
            if(sp[i]==i){
              v.push_back(i);
              if(m.count(i))return m[i];
            }
            if(i*i!=n)
                if(sp[n/i]==n/i)v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    for(auto i:v)
              if(m.count(i))return m[i];
    if(v.size()>=4)m[n]=v;
    return v;
}
void solve(){
  int n;cin>>n;
  vi v(n),b(n,-1),c(n,-1);
  rep(i,0,n-1){
    cin>>v[i];
  }
  rep(j,0,n-1){
    int spf=sp[v[j]],ori=v[j];bool x=0;int d[2]={1,1};
    while(v[j]!=1){
      int spf=sp[v[j]];
      while((v[j]%spf)==0)v[j]/=spf;
      d[x^=1]*=spf;
    }
    if( d[0]!=1 and d[1]!=1 /*and __gcd(d[0]+d[1],ori)!=1*/ )
      b[j]=d[0],c[j]=d[1];
  }
  rep(i,0,n-1)cout<<b[i]<<" ";cout<<"\n";
  rep(i,0,n-1)cout<<c[i]<<" ";
}
int32_t main()
{
  ibs;cti;
  // gen_primes();
  Sieve();
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
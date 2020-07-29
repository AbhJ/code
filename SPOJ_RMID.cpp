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
// #define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
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
priority_queue<int>ma;
priority_queue<int,vi,greater<int>>mi;
int n;
void f(){
  if(mi.empty() and ma.empty()){
    mi.push(n);return;
  }
  int med;
  if(mi.empty())med=ma.top();
  if(ma.empty())med=mi.top();
  if(ma.empty()==0 and mi.empty()==0){
    med=ma.top();
  }
  if(n>med){
    mi.push(n);return;
  }
  if(n<=med){
    ma.push(n);return;
  }
}
void q(){
  if(ma.empty()){
    cout<<mi.top()<<"\n";
    mi.pop();
    return;
  }
  if(mi.empty()){
    cout<<ma.top()<<"\n";
    ma.pop();
    return;
  }
  if(mi.size()==1+ma.size()){
    cout<<mi.top()<<"\n";
    mi.pop();
    return;
  }
  if(ma.size()==1+mi.size()){
    cout<<ma.top()<<"\n";
    ma.pop();
    return;
  }
  if(mi.size()==ma.size()){
    cout<<ma.top()<<"\n";
    ma.pop();
    return;
  }
}
void res(){
  if(mi.size()>=2+ma.size()){
    int t=mi.top();
    mi.pop();
    ma.push(t);
    return;
  }
  if(ma.size()>=2+mi.size()){
    int t=ma.top();
    ma.pop();
    mi.push(t);
    return;
  }
}
void solve(){
  while(scanf("%lld",&n)!=EOF){
    if(n==0){
      cout<<"\n";
      ma=priority_queue<int>();
      mi=priority_queue<int,vi,greater<int>>();
    }
    if(n==-1)q();
    if(n>0)f();
    res();
    //f inserts
    //q queries
    //res resets size
  }
}
int32_t main()
{
  // ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
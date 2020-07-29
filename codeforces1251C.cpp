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
// const int N=70;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
string s;queue <char> q,Q; 
void solve(){
  cin>>s;for(auto i:s){if((i-'0')&1)Q.push(i);else q.push(i);}
  while(q.empty()==0 or Q.empty()==0){
    if(Q.empty()==1){cout<<q.front(),q.pop();continue;}
    if(q.empty()==1){cout<<Q.front(),Q.pop();continue;}
    if(q.front()>Q.front()){cout<<Q.front(),Q.pop();continue;}
    cout<<q.front(),q.pop();
  }
}
int32_t main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;
  while(t--){solve();cout<<"\n";}
  return 0;
}
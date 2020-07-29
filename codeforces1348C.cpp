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
// #include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e2+30;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
void solve(){
  int n,k;cin>>n>>k;
  string s;cin>>s;
  sort(s.begin(), s.end());
  if(s[k-1]!=s[0]){cout<<s[k-1];return;}
  if(s[k]!=s[n-1]){
    cout<<s[0];
    for (int i = k; i < n; ++i)
    {
      cout<<s[i];
    }
    return;
  }
  cout<<s[0];//if the s[k] repeats from k to n-1
  for (int i = 0; i < (n-1)/k; ++i)
  {
    cout<<s[k];
  }
}
int main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;
  while(t--){solve();cout<<"\n";}
  return 0;
}
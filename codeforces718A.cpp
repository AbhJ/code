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
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e15;
const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,t,i,l,integer_part_len;string s;
void done(){
  if(i==-1)//everydigit changed
    s="1"+s;
  cout<<s+"\n";
  exit(0);
}
void solve(){
  cin>>n>>t>>s;l=s.length();
  for(i=0;i<l and s[i]!='.';i++);
  integer_part_len=i++-1;//we are now in decimal region
  for(;s[i]<'5' and i<l;i++);//leads us to first roundable digit after decimal
  if(s[--i]=='4'){
    //we round up as much possible
    //we pay per round up
    //turns 29.999944444555666888 into 29.99995
    for(;s[i]=='4' and --t and i>integer_part_len+1;)i--;
    // cout<<s;
  }
  s=s.substr(0,i+1);
  if(i==l-1)
    // cout<<"F";
    //nothing to be rounded
    done();
  // cout<<i;
  for(;i>-1;i--){
    //these 9s could get 29.9999 or 29.999944444555555
    if(s[i]=='9' or s[i]=='.'){
      //we paid for this while we were rounding off 4s
      if(i>integer_part_len)//in the decimal region
        s.erase(s.begin()+i);
      else s[i]='0';
    }
    else s[i]++,done();
  }
  done();
}
int32_t main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}
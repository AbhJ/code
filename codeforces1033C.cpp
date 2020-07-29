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
const int N=1e5+10;
const int inf = /*0x3f3f3f3f*/ 1e18+12;
// const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int a[N],B[N],n;bool b[N];
void solve(){
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i],B[a[i]]=i;
  for(int i=n;i>=1;i--){
    int c=0;
    for(int j=B[i]%i;j<n;j+=i)
      if(a[j]>i and b[j]==0){
        b[B[i]]=1;break;
      }
  }
  for(int i=0;i<n;i++){if(b[i]==1)cout<<"A";else cout<<"B";}
  // for(int i=1;i<=n;i++)cout<<b[i];
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
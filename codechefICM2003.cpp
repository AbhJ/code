#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <numeric>
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
#include <bits/stdc++.h>
#define double long double
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e9;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
double b,c;
double F(double x){
  double xx= (((x*x)+(x*b)+c));
  xx/=sin(x);
  return xx;
}
int32_t main()
{
  ibs;cti;
  double Z=1e-6;
  // solve()
  /*,cout<<"\n"*/;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*//*;*/cin>>b>>c;
  int x=0;
  double l=1e-7;double r=(Pi/2.00)-1e-7;
   while (r - l > Z) {
      double m1 = l + (r - l) / 3;
      double m2 = r - (r - l) / 3;
      if (F(m1) > F(m2))
          l = m1;
      else
          r = m2;
      if(x++ > 20) break;
  }
  double ans=F(l);
  cout<<setprecision(20)<<ans;cout<<"\n";}
  return 0;
}
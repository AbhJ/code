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
#define res(vector) v.resize(unique(v.begin(), v.end()) - v.begin());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,k,x,y,A[N],a[N],result[N];
int mul(int a,int b);
ll fact_dp(int n)

{

    if (n >= 0) 

    {

        result[0] = 1;

        for (int i = 1; i <= n; ++i) 

        {

            result[i] = mul(i ,result[i - 1]);

        }

        return result[n];

    }

}
int mul(int a,int b){
  return ((a%M)*(b%M))%M;
}
void solve(){
  cin>>n;
  fact_dp(n);
  // for(int i=1;i<=n;i++)cin>>A[i];
  for(int i=1;i<=n-1;i++){
    cin>>x>>y;
    a[x]++,a[y]++;
  }
  k=n;
  for(int i=1;i<=n;i++)k=mul(k,result[a[i]]);
  cout<<k;
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();/*cout<<"\n";*/}
  return 0;
}
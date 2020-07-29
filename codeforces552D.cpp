#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
// #include <numeric>
#include <vector>
// #include <iterator> 
// #include <map>
#include <set>
// #include <climits>
// #include <queue>
// #include <iomanip>
// #include <cmath>
// #include <stack>
#include <cctype>
// #include <bits/stdc++.h>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e3+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int a[N],b[N],n,c;
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
  for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
      for(int k=j+1;k<=n;k++)
        if(a[i]*(b[j]-b[k])+a[j]*(b[k]-b[i])+a[k]*(b[i]-b[j])!=0)
          c++;
  cout<<c;
  //matrix's determinant should not be zero as no two point are collinear
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
}
//following is a better solution
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
const int N=2e3+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
double a[N],b[N];int n,c,ans;
map<double,int>m;
long long C(long long n,long long r)
{
   if(r==2)return(n*(n-1)/2);
   else return(n*(n-1)*(n-2)/6);
}
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
  for(int i=1;i<=n;i++){
    m.clear();
    for(int j=i+1;j<=n;j++){
      if(b[i]!=b[j])
      m[(a[i]-a[j])/(b[i]-b[j])]++;
      else
      m[M+2]++;
    }
    for(auto i:m)ans-=C(i.S,2);
  }
  ans+=C(n,3);
  cout<<ans;
}
int main()
{
  ibs;cti;
  solve(),cout<<"\n";
  // int t;cin>>t;
  // while(t--){solve();cout<<"\n";}
  return 0;
// }
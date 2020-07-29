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
// #include <bits/stdc++.h>
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+1;
const int inf = /*0x3f3f3f3f*/1e15;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int n,a[N],p[N],q[N],ans[N];
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];p[i]=a[i]+p[i-1];
  }
  p[n+1]=p[n];
  for(int i=1;i<=n;i++){
    cin>>q[i];
  }
  multiset<int>s;s.insert(0),s.insert(n+1);
  //s contains blocked indices
  multiset<int>S;S.insert(0),S.insert(p[n]);
  //S contains current possible segment sums
  //both multisets are dynamic
  for(int i=1;i<=n;i++){
    //the blocked index above this
    int end=*(s.upper_bound(q[i]))-1;
    //end is the upper most unblocked element after q[i]
    int start=*prev(s.upper_bound(q[i]));
    //start is the blocked index just previous to end
    S.erase(S.find(p[end]-p[start]));
    S.insert(p[q[i]-1]-p[start]);
    S.insert(p[end]-p[q[i]]);
    s.insert(q[i]);
    //we always choose biggest segment sum
    ans[i]=*S.rbegin();
  }
  for (int i = 1; i <= n; ++i)
  {
    cout<<ans[i]<<"\n";
  }
}
int32_t main()
{
  ibs;cti;
  solve()/*,cout<<"\n"*/;
  int x=0;
  // int t;cin>>t;while(t--){solve();cout<<"\n";}
  return 0;
}
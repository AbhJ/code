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
const int N=1e2+10;
const int inf = 0x3f3f3f3f;
// const ll M = 998244353 ; // Mulo
const ll M = 1e9+7 ; // Mulo
#define F first
#define S second
int a[N],v[N];
set<int>s[N];
int z;
int minimumSwaps(int arr[],int n,int st) 
{ 
    // Initialise count variable 
    int c = 0; 
    int i = st; 
      
    for (int j = 0; j < n; ++j)
    { 
        i=v[st+j];
        // If current element is 
        // not at the right position 
        if (arr[i] != i) 
        { 
  
            while (arr[i] != i)  
            { 
                int temp = 0; 
  
                // Swap current element 
                // with correct position 
                // of that element 
                if(s[i].count(arr[i])==1){
                    s[i].erase(arr[i]),s[arr[i]].erase(i);
                    c--;
                }
                // cout<<i<<" "<<arr[i]<<"\n";
                temp = arr[arr[i]]; 
                arr[arr[i]] = arr[i]; 
                arr[i] = temp;
                c++; 
            } 
            
        }
        // Increment for next index 
        // when current element is at 
        // correct position 
        // i++; 
    } 
    return c; 
}
int n,m;
void solve(){
  cin>>n>>m;z=1e9;
  for(int i=1;i<=n;i++)s[i].clear();
  for (int i = 1; i <= n; ++i)cin>>a[i];
  int i;
  for ( i = 1; i <= n; ++i)v[i]=i;
  for (i=n+1; i <= 2*n; ++i)v[i]=i-n;
  // for (i=1; i <= 2*n; ++i)cout<<v[i]<<" ";
  while(m--){
    int x,y;cin>>x>>y;
    s[x].insert(y);s[y].insert(x);
  }
  int b[n+10];
  for (int i = 1; i <= n; ++i)
  {
      for (int j = 1; j <= n; ++j)
      {
        b[j]=a[j];
      }
      z=min(z,minimumSwaps(b,n,i));
  }
  // z=minimumSwaps(a,n);
  cout<<z;
}
int main()
{
  ibs;cti;
  // solve(),cout<<"\n";
  int t;cin>>t;
  while(t--){solve();cout<<"\n";}
  return 0;
}
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
const int N=1e6+10;
const int inf = /*0x3f3f3f3f*/ 1e18+12;
// const int M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
#define F first
#define S second
int findMinSwap(int arr[] , int n) 
{ 
    // Declare a vector of pair      
    vector<pair<int,int>> vec(n); 
      
    for(int i=0;i<n;i++) 
    { 
        vec[i].first=arr[i]; 
        vec[i].second=i; 
    } 
  
    // Sort the vector w.r.t the first 
    // element of pair 
    sort(vec.begin(),vec.end()); 
  
    int ans=0,c=0,j; 
  
    for(int i=0;i<n;i++) 
    {    
        // If the element is already placed 
        // correct, then continue 
        if(vec[i].second==i)  
            continue; 
        else
        { 
            // swap with its respective index  
            swap(vec[i].first,vec[vec[i].second].first); 
            swap(vec[i].second,vec[vec[i].second].second);  
        }  
          
        // swap until the correct  
        // index matches 
        if(i!=vec[i].second) 
            --i; 
          
        // each swap makes one element 
        // move to its correct index,  
        // so increment answer 
        ans++; 
    } 
  
    return ans; 
}
int n,a[N],c,b[N];
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  c=findMinSwap(a+1,n);
  if(((n*3)%2 ^ c%2 )==0)cout<<"Petr";
  else cout<<"Um_nik";
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
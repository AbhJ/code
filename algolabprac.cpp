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
#define pb emplace_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
#define deb(x) cout<<"\n["<<#x<<" = "<<x<<"]\n";
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int maxProfit(int price[], int start, int end) 
{ 
  
    // If the stocks can't be bought 
    if (end <= start) 
        return 0; 
  
    // Initialise the profit 
    int profit = 0; 
  
    // The day at which the stock 
    // must be bought 
    for (int i = start; i < end; i++) { 
  
        // The day at which the 
        // stock must be sold 
        for (int j = i + 1; j <= end; j++) { 
  
            // If byuing the stock at ith day and 
            // selling it at jth day is profitable 
            if (price[j] > price[i]) { 
  
                // Update the current profit 
                int curr_profit = price[j] - price[i] 
                                  + maxProfit(price, start, i - 1) 
                                  + maxProfit(price, j + 1, end); 
  
                // Update the maximum profit so far 
                profit = max(profit, curr_profit); 
            } 
        } 
    } 
    return profit; 
} 
int n,k,a[N];
void solve(){
  cin>>n;
  rep(i,0,n-1)cin>>a[i];
  cout<<1000+maxProfit(a,0,n-1);
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
const long M = 1000000007; // modulo
ll solve(ll n){
  if(n<=250000)return n;
  if(n<=500000)return 95*(n-250000)/100+solve(250000);
  if(n<=750000)return 90*(n-500000)/100+solve(500000);
  if(n<=1000000)return 85*(n-750000)/100+solve(750000);
  if(n<=1250000)return 80*(n-1000000)/100+solve(1000000);
  if(n<=1500000)return 75*(n-1250000)/100+solve(1250000);
  return 70*(n-1500000)/100+solve(1500000);
}
int main()
{   
    ibs;cti;int t;cin>>t;
    while(t--){
      ll n;cin>>n;
      cout<<solve(n)<<"\n";
    }
    // cout<<day_of_week(2020,3,1);
    return 0;
}
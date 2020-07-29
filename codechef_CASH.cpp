#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
const long M = 1000000007; // modulo
// int m[2][N];//the grid
int main()
{   
    ibs;cti;int t;cin>>t;
    while(t--){
      ll n,k,ans=0;cin>>n>>k;std::vector<int> v(n);
      for(int i=0;i<n;i++)cin>>v[i];
      for(auto i:v)ans=(ans+i)%k;
      cout<<ans%k<<"\n";      
    }
    return 0;
}
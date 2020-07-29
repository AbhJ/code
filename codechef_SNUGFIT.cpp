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
      int n;cin>>n;
      std::vector<int> a(n),b(n);ll sum=0;
      for (int i = 0; i < n; ++i)cin>>a[i];
      for(int i=0;i<n;i++)cin>>b[i];
      sort(a.begin(), a.end());sort(b.begin(), b.end());
      for (int i = 0; i < n; ++i)
        sum+=min(a[i],b[i]);
      cout<<sum<<"\n";
    }
    return 0;
}
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
      std::vector<int> a(n),b(n);int num_of_discontinuous_series=0;
      for (int i = 0; i < n; ++i)cin>>a[i];
      for(int i=0;i<n;i++)cin>>b[i];bool c=0;
      for (int i = 0; i < n; ++i)
      {
        b[i]-=a[i];
        if(b[i]<0){c=1;break;}
        if(b[i]>0 and b[i]!=b[i-1])num_of_discontinuous_series++;
        if(num_of_discontinuous_series>1){c=1;break;}
      }
      c?cout<<"NO\n":cout<<"YES\n";
    }
    return 0;
}
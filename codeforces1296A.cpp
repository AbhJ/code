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
    ibs;cti;int t;cin>>t;while(t--){
      int n;cin>>n;int v;
      int odd=0,even=0;
      for (int i = 0; i < n; ++i)
      {
        cin>>v;v%2?odd++:even++;
      }
      if(!odd){
        cout<<"NO\n";continue;
      }
      if(odd%2)
        cout<<"YES\n";
      else{
        if(even)
          cout<<"YES\n";
        else cout<<"NO\n";
      }

    }
    return 0;
}
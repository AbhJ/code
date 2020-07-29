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
      int n;cin>>n;int v=0;
     int pw = 1000 * 1000 * 1000;
      while (n > 0) {
      while (n < pw) pw /= 10;
      v += pw;
      n -= pw - pw / 10;
     }
      cout<<v<<"\n";
    }
    return 0;
}
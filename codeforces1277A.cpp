#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define M 1000000007
#define N 100000
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;int t;cin>>t;
    while(t--){
      int n;cin>>n;
      int b = 0, ans = 0;
      for (int len = 1; len <= 9; len++) {
          b = b * 10 + 1;            
          for (int m = 1; m <= 9; m++)if (b * m <= n)ans++;
      }
      cout << ans << endl;
    }
    return 0;   
}
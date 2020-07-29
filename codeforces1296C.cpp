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
      string s;cin>>s;
      int l = -1, r = n;
      map<pair<int, int>, int> m;
      pair<int, int> pos = {0, 0};
      m[pos] = 0;
      for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') --pos.first;
        if (s[i] == 'R') ++pos.first;
        if (s[i] == 'U') ++pos.second;
        if (s[i] == 'D') --pos.second;
        if (m.count(pos)) {
          if (i - m[pos] + 1 < r - l + 1) {
            l = m[pos];
            r = i;
          }
        }
        m[pos] = i + 1;
      }
      if (l == -1) {
        cout << -1 << endl;
      } else {
        cout << l + 1 << " " << r + 1 << endl;
      }
    }
    return 0;
}
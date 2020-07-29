#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
// std::vector<pair<int,int>> S[200009];//index are duration
ll result[100000] = {0};
ll fact(ll n) {
   if (n >= 0) {
      result[0] = 1;
      for (ll i = 1; i <= n; ++i) {
         result[i] = i * result[i - 1];
      }
      return result[n];
   }
}
int main()
{
    ibs;cti;
    int n,m;cin>>n>>m;
    cout<<fact(min(n,m))<<"\n";
    return 0;
}
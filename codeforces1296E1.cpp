#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
const long M = 1000000007; // modulo
int main()
{   
    ibs;cti;
      ll n;cin>>n;
      string s;cin>>s;char a=CHAR_MIN,b=CHAR_MIN;
      std::vector<bool> v(n);
      for (int i = 0; i < n; ++i)
      {
        if(s[i]>=a)a=s[i],v[i]=0;
        else if(s[i]>=b)b=s[i],v[i]=1;
        else {cout<<"NO\n";return 0;}
      }
      cout<<"YES\n";
      for (int i = 0; i < n; ++i)cout<<v[i];
      cout<<"\n";
    // cout<<day_of_week(2020,3,1);
    return 0;
}
#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
void fact(int n)
{
    // vector<int> v;
    for(int i=2;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            cout<<i<<n/i;
        }
    }
    // sort(v.begin(),v.end());
    // reverse(v.begin(),v.end());
    // return v;
}
void solve(){
  int n;cin>>n;
  fact(n);
}
int main()
{
    ibs;cti;
    // int t;cin>>t;
    // while(t--){
      solve();
      cout<<"\n";
    // }
    return 0;
}
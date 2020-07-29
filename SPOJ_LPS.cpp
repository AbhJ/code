#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e7+3;
const int M = 1000000007; // modulo
int P[N+1];
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
vector<int> fact(int n)
{
    vector<int> v;
    for(int i=1;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            v.push_back(i);
            if(i*i!=n)
                v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    return v;
}
//using manacher's algorithms
void solve(){
      int n;cin>>n;string s,T="@";cin>>s;int ans=0;
      for (int i = 0; i < s.length(); ++i)
      {
        T+="#"+s.substr(i, 1);
      }
      T+="#$";
      int c=0,r=0;
      for (int i = 1; i < T.size() - 1; i++){
        // find the corresponding letter in the palidrome subString
        int iMirror = c - (i - c);
        if(r > i) 
            P[i] = min(r - i, P[iMirror]);
        // expanding around center i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            P[i]++;
        // Update c,r in case if the palindrome centered at i expands past r,
        if (i + P[i] > r)
            c = i,r = i + P[i];
        ans=max(ans,P[i]);
      }
      cout<<ans;
}
int main()
{   
    ibs;cti;
    solve();
    cout<<"\n";
    return 0;
}
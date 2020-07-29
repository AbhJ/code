#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e7+3;
const int M = 1000000007; // modulo
// ll dp[1000][1000];
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
void solve(){
  int n;cin>>n;
  string s;cin>>s;int a=0,b=0,A=n,B=n,ans=0,i;
  for (i = 0; i < 2*n; i++)
  {
    if(i%2){
      if(s[i]=='1')b++;
      B--;
      if(b<a and b+B<a){cout<<i+1<<"\n";return;}
      if(a<b and a+A<b){cout<<i+1<<"\n";return;}
    }
    else{
      if(s[i]=='1')a++;
      A--;
      if(b<a and b+B<a){cout<<i+1<<"\n";return;}
      if(a<b and a+A<b){cout<<i+1<<"\n";return;}
    }
  }
  cout<<2*n<<"\n";
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)solve();
    cout<<"\n";
    return 0;
}
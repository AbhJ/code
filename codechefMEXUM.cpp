#include <bits/stdc++.h>
// #include <xeric>QC
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=1e5+10;
const ll M = 998244353 ; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
ll gcdExtended(ll a, ll b, ll *x, ll *y); 
  
// Function to find modulo inverse of b. It returns 
// -1 when inverse doesn't 
ll modInverse(ll b, ll m) 
{ 
    ll x, y; // used in extended GCD algorithm 
    ll g = gcdExtended(b, m, &x, &y); 
  
    // Return -1 if b and m are not co-prime 
    if (g != 1) 
        return -1; 
  
    // m is added to handle negative x 
    return (x%m + m) % m; 
} 
  
// Function to compute a/b under modlo m 
ll div(ll a, ll b, ll m=M) 
{ 
    a = a % m; 
    ll inv = modInverse(b, m); 
    // if (inv == -1) 
    //    cout << "Division not defined"; 
    // else
       return (inv * a) % m; 
} 
  
// C function for extended Euclidean Algorithm (used to 
// find modular inverse. 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}
ll mul(ll a,ll b){
  return ((a%M)*(b%M))%M;
}
ll add(ll a,ll b){
  return ((a%M)+(b%M))%M;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
ll a,p[N];map<ll,ll>m;
void solve(){
  int n;cin>>n;
  m.clear();
  for (int i = 0; i < n; ++i)
  {
    cin>>a;m[a]++;
  }
  ll C=n,P=1,ans=0;
  for (ll i = 1; i <=n+1; ++i)
  {
    C=sub(C,m[i]);
    ans=add(ans,mul(i,mul(p[C],P)));
    P=mul(P,sub(p[m[i]],1));
  }
  cout<<ans;
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    p[0]=1;
    for (int i = 1; i < N; ++i)
    {
      p[i]=mul(2,p[i-1]);
    }
    while(t--){
      solve();
      // cout<<len;
      cout<<"\n";
    }
    return 0;
}
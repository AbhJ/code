#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=3e5+10;
const ll M =  998244353; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
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
ll modDivide(ll a, ll b, ll m=M) 
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
void solve(){
  string s;cin>>s;
  stack<char>s1;//operator
  stack<pair<ll,ll>>s2;//probability
  int o=0,c=0;
  if(s.length()==1){cout<<"748683265 748683265 748683265 748683265";return;}
  for (int i = 0; i < s.length(); ++i)
  {
    if(s[i]=='(')o++;
    if(s[i]=='#')s2.push({-1,-1});
    if(s[i]=='&')s1.push('&');
    if(s[i]=='|')s1.push('|');
    if(s[i]=='^')s1.push('^');
    if(s[i]==')'){
      auto p1=s2.top();
      s2.pop();
      auto p2=s2.top();
      s2.pop();
      if(p2<p1)swap(p1,p2);
      char C=s1.top();
      s1.pop();
      ll f,s;
      //f for getting 1
      //s for getting 0
      if(p1.F==-1 and p2.F==-1){
        int n,d;
        if(C=='&')n=4,d=16;
        if(C=='|')n=12,d=16;
        if(C=='^')n=1,d=2;
        f=modDivide(n,d),s=modDivide((d-n),d);
      }
      else if(p1.F==-1){
        int n=2,d=4;
        if(C=='&')f=mul(modDivide(n,d),p2.F);
        if(C=='|')f=sub(1,mul(p2.S,modDivide(d-n,d)));
        if(C=='^')f=add(mul(modDivide(n,d),p2.S),mul(modDivide(d-n,d),p2.F));
        s=sub(1,f);
      }
      else{
        if(C=='&')f=mul(p1.F,p2.F);
        if(C=='|')f=sub(1,mul(p2.S,p1.S));
        if(C=='^')f=add(mul(p1.F,p2.S),mul(p1.S,p2.F));
        s=sub(1,f);
      }
      s2.push({f,s});
    }
  }
  auto x=s2.top();
  cout<<mul(x.S,x.S)<<" "<<mul(x.F,x.F)<<" "<<mul(x.F,x.S)<<" "<<mul(x.F,x.S);
}
int main()
{
    ibs;cti;
    int t;cin>>t;
    while(t--){
      solve();
      cout<<"\n";
    }
    return 0;
}
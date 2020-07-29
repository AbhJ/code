#include <bits/stdc++.h>
#define ll long long int
#define N 100000
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
using namespace std;ll C[N+100];
// C function for extended Euclidean Algorithm 
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
ll modDivide(ll a, ll b, ll m) 
{ 
    a = a % m; 
    ll inv = modInverse(b, m);
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
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs,cti;
    int t;cin>>t;
    while(t--){
        int n1;cin>>n1;string a1,b1;cin>>a1>>b1;
        bitset<N> A(a1), B(b1);
        int a= A.count(),b=B.count();
        int best=abs(b-a),worst=a+b;
        if (a+b>n1)
            worst=2*n1-a-b;
        ll sum=0;C[0]=1;C[1]=n1;
        for (int i = 2; i <= worst; ++i)
            // C[i]=((n1-i+1)%M)*C[i-1]/i;C[i]%=M;
            C[i]=modDivide(((n1-i+1)*C[i-1]),i,M);
        for (int i = best; i <=worst ; i+=2){
            sum+=C[i];sum%=M;
        }
        cout<<sum<<"\n";
    }
    return 0;
}
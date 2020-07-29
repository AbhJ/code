#include <bits/stdc++.h>
// #include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
// const int N=3e5+10;
const ll M =  1e9+7; // Mulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
// bool u[N];int s;
// int A[N],B[N];int S[N];
vector<vector<int>> a;
void bfs(int s,int* d) {
  d[s] = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();q.pop();
    for (auto to : a[v]) {
      // cout<<d[to]<<" "<<to<<"\n";
      if (d[to] == 0) {
        d[to] = d[v] + 1;
        q.push(to);
      }
    }
  }
}
// void dfs(int x){
//     if(u[x])return;
//     u[x]=1;s++;
//     // if(st)c[x]=i+1;
//     for(int y:a[x])if(!u[y])
//         dfs(y);
// }

ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
ll powM(ll a,ll b)
{
  ll ans=1;
  while(b)
  {
    if(b&1LL)ans=ans*a%M;
    a=a*a%M;
    b>>=1;
  }
  return ans;
}
// struct b{int w,pos;}A[N];
int findMax(set<int> my_set) 
{ 
  
    // Get the maximum element 
    int max_element; 
    if (!my_set.empty()) 
        max_element = *(my_set.rbegin()); 
  
    // return the maximum element 
    return max_element; 
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
    // sort(v.begin(),v.end());
    // reverse(v.begin(),v.end());
    return v;
}
std::vector<int> printKPFNums(int A, int B, int K) 
{ 
    // Count prime factors of all numbers 
    // till B. 
  std::vector<int> v;
    bool prime[B+1] = { true }; 
    int p_factors[B+1] = { 0 }; 
    for (int p = 2; p <= B; p++)  
        if (p_factors[p] == 0)  
            for (int i = p; i <= B; i += p)  
                p_factors[i]++; 
  
    // Print all numbers with k prime factors 
    for (int i = A; i <= B; i++)  
        if (p_factors[i] == K) 
            v.pb(i);

          return v;
} 
void sieveOfEratosthenes(int N, int s[]) 
{ 
    // Create a boolean array "prime[0..n]" and 
    // initialize all entries in it as false. 
    vector <bool> prime(N+1, false); 
  
    // Initializing smallest factor equal to 2 
    // for all the even numbers 
    for (int i=2; i<=N; i+=2) 
        s[i] = 2; 
  
    // For odd numbers less then equal to n 
    for (int i=3; i<=N; i+=2) 
    { 
        if (prime[i] == false) 
        { 
            // s(i) for a prime is the number itself 
            s[i] = i; 
  
            // For all multiples of current prime number 
            for (int j=i; j*i<=N; j+=2) 
            { 
                if (prime[i*j] == false) 
                { 
                    prime[i*j] = true; 
  
                    // i is the smallest prime factor for 
                    // number "i*j". 
                    s[i*j] = i; 
                } 
            } 
        } 
    } 
}
// Function to generate prime factors and its power 
int generatePrimeFactors(int N) 
{ 
    // s[i] is going to store smallest prime factor 
    // of i.
    ll ans=0; 
    int s[N+1]; 
  
    // Filling values in s[] using sieve 
    sieveOfEratosthenes(N, s); 
  
    // printf("Factor Power\n"); 
  
    int curr = s[N];  // Current prime factor of N 
    int cnt = 1;   // Power of current prime factor 
  
    // Printing prime factors and their powers 
    while (N > 1) 
    { 
        N /= s[N]; 
  
        // N is now N/s[N].  If new N als has smallest 
        // prime factor as curr, increment power 
        if (curr == s[N]) 
        { 
            cnt++; 
            continue; 
        } 
  
        // printf("%d\t%d\n", curr, cnt); 
        ans+=cnt;
  
        // Update current prime factor as s[N] and 
        // initializing count as 1. 
        curr = s[N]; 
        cnt = 1; 
    } 
    return ans;
}
ll primeFactors(ll n)  
{  
  ll ans=0;
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        ans++;
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            ans++;
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        ans++;
    return ans;
}  
void solve(){
  ll x,k;
  cin>>x>>k;
  cout<<(primeFactors(x)>=k);
  // if(x<powM(2,k)){cout<<0;return;}
  // ll s=fact(x).size()+1;
  // if(s>=k)cout<<1;else cout<<0;
  // else cout<<1;
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
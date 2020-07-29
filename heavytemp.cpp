#include <bits/stdc++.h>
#include <numeric> 
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
#define eb emplace_back
using namespace std;//coded by abhijay mitra
const int N=3e5+3;
// const int N=300;
const ll M = 998244353; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
#define LIM 1LL<<62-1;
 using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int dfs(int u=1,int p=0,int level=0){
  ll subtree=0;
  for(auto i:a[u])if(i!=p){
    subtree+=dfs(i,u,level+1);
  }
  q.push(level-subtree);
  return subtree+1;
}
ll dfs(int x,int i,int pls=1,bool st=0){
    u[x]=1;
    if(st)c[x]=i+1;
    for(int y:e[x])if(!u[y])
        return v[i][x]+dfs(y,(i+pls)%3,pls,st);
    return v[i][x];
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
//simplifies x/y
pair<int,int> simplify_fraction(int x,int y)
{
  int g=__gcd(x,y);
  x/=g,y/=g;
  if(x<0)
    x=-x,y=-y;
  return {x,y};
}
int mul(int a,int b){
  return ((a)*(b))%M;
}
int add(int a,int b){
  a+=b;
  if(a>=M)a-=M;
  return a;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
int invM(int x){
  return powM(x,M-2);
}
void binomialCoeff(int n) 
{ 
  f[0]=b[0]=1;
  rep(i,1,n){
    f[i]=mul(f[i-1],i);
    b[i]=invM(f[i]);
  }
  rep(i,1,n){
    C[i]=mul(mul(f[n],b[n-i]),b[i]);
  }
} 
int binomialCoeffUtil(int n, int k, int** dp) 
{ 
    // If value in lookup table then return 
    if (dp[n][k] != -1) //      
        return dp[n][k]; 
  
    // store value in a table before return 
    if (k == 0) { 
        dp[n][k] = 1; 
        return dp[n][k]; 
    } 
      
    // store value in table before return 
    if (k == n) { 
        dp[n][k] = 1;  
        return dp[n][k]; 
    } 
      
    // save value in lookup table before return 
    dp[n][k] = binomialCoeffUtil(n - 1, k - 1, dp) + 
               binomialCoeffUtil(n - 1, k, dp); 
    return dp[n][k]; 
} 
  
int binomialCoeff(int n, int k) 
{ 
    int** dp; // make a temporary lookup table 
    dp = new int*[n + 1]; 
  
    // loop to create table dynamically 
    for (int i = 0; i < (n + 1); i++) { 
        dp[i] = new int[k + 1]; 
    } 
  
    // nested loop to initialise the table with -1 
    for (int i = 0; i < (n + 1); i++) { 
        for (int j = 0; j < (k + 1); j++) { 
            dp[i][j] = -1; 
        } 
    } 
  
    return binomialCoeffUtil(n, k, dp); 
} 
int binomialCoeff(int n, int k) 
{ 
    int C[k+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;  // nC0 is 1 
  
    for (int i = 1; i <= n; i++) 
    { 
        // Compute next row of pascal triangle using 
        // the previous row 
        for (int j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 
int mul(int a,int b){
  return ((a)*(b))%M;
}
int add(int a,int b){
  a+=b;
  if(a>=M)a-=M;
  return a;
}
vvi p(vvi a,vvi b){
  vvi x(n,vi(n,0));
  rep(i,0,n-1)
    rep(j,0,n-1)
      rep(k,0,n-1)
        x[i][j]=add(x[i][j],mul(a[i][k],b[k][j]));
  return x;
}
vvi a;
//this return pow(A,x) where A is matrix
vvi matrix_power_final(vvi A, int x){
  vvi result(n,vi(n,0));
  rep(i,0,n-1)result[i][i]=1;
  while(x){
    if (x&1)result = p(result , A);
    A = p(A , A);
    x = x / 2;
  }
  return result;
}
std::vector<int> bfs(int s) {
  std::vector<int> r;
  u[s]=1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    r.pb(v);q.pop();
    for (auto to : a[v]) {
      if (u[to] == 0) {
        u[to] = 1;
        q.push(to);
      }
    }
  }
  return r;
}
void bfs1(int s){
    queue<int> qu;  
    fill(vis, 0);
 
    qu.push(s);
    vis[s] = 1;
    dt[s]  = 0;
 
    while(!qu.empty()){
        int c = qu.front();
        qu.pop();
 
        for(auto x:adj1[c]){
            if(!vis[x]){
                qu.push(x);
                vis[x] = 1;
                dt[x] = dt[c] + 1;
            }
        }
    }
}
int n;
int A[N],e[N][N];
std::vector<int> v;
void dfs(int x){
    if((int)v.size()>k)return;
    // if(u[x])return;
    u[x]=1;
    v.pb(x);
    // if(st)c[x]=i+1;
    for(int y:a[x])if(!u[y])
        dfs(y);
}
bool is(string str) 
{ 
    // Start from leftmost and rightmost corners of str 
    int l = 0; 
    int h = str.length() - 1; 
  
    // Keep comparing characters while they are same 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
            
            return 0; 
        } 
    } 
    return 1;
}
int parent[N],ind[N];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    ind[v] = rand();
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ind[a] < ind[b])
            swap(a, b);
        parent[b] = a;
    }
}
//disjoint set union dsu
 int lcm(int a, int b)  
 {  
    return (a*b)/__gcd(a, b);  
 }  
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}bool p[N];
void calc(){
  memset(p,1,sizeof(p));
  p[0]=p[1]=0;
  for (ll i = 4; i <= 10000; i += 2) {
      p[i] = 0;
  }
  for (ll i = 9; i <= 10000; i += 6) {
      p[i] = 0;
  }
  for (ll i = 5; i * i <= 10000; i += 6) {
      if (p[i]) {
          for (ll j = i * i; j <= 10000; j += 2 * i) {
              p[j] = 0;
          }
      }
      if (p[i + 2]) {
          for (ll j = (i + 2) * (i + 2); j <= 10000; j += (2 * (i + 2))) {
              p[j] = 0;
          }
      }
  }
}
// ll powM(ll a,ll b)
// {
//   ll ans=1;
//   while(b)
//   {
//     if(b&1LL)ans=ans*a%M;
//     a=a*a%M;
//     b>>=1;
//   }
//   return ans;
// }
//spf
int sp[(int)1e7+1LL];
bool v[(int)1e7+1LL];
void gen_primes() {
  int i,j;
  for(i=0;i<1e7+1;i++) p[i] = 1;
  for(i=2;i<=(int)sqrt(1e7+1);i++)
  if (p[i])
  for(j=i;j*i<1e7+1;j++) p[i*j] = 0;
}
void Sieve(){
  for (int i = 2; i < 1e7+1; i += 2)  sp[i] = 2;//even numbers have smallest prime factor 2
  for (int  i = 3; i < 1e7+1; i += 2){
    if (!v[i]){
      sp[i] = i;
      for (int j = i; (j*i) < 1e7+1; j += 2){
        if (!v[j*i])  v[j*i] = true, sp[j*i] = i;
      }
    }
  }
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
//finds fibo(n) in log n
map<int, int> F;
int f(int n) {
  //initialize F[0],F[1],F[2] before calling this function;
  if (F.count(n)) return F[n];
  int k=n/2;
  if (n%2==0) { // n=2*k
    return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
  } else { // n=2*k+1
    return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
  }
}
ll div(ll n)
{
    int d[1000001]={0};
    for(int i=1;i<=1000000;i++)
        for(int j=i;j<=1000000;j+=i)
            d[j]++;
    return d[n];
}
double dist(pair<double,double>a,pair<double,double>b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
int f[N],b[N];
void calc_fact(){
  f[0]=b[0]=1;
  rep(i,1,N-1){
    f[i]=mul(f[i-1],i);
    b[i]=powM(f[i],M-2);
  }
}
int C(int n,int r){
  assert(n<N);assert(r<N);
  if(r>n)return 0;
  return (f[n]*(b[r]*b[n-r])%M)%M;
}
int mex() {
  map<int, bool> m;
  for (int i = 0; i < n; i++) m[a[i]] = true;
  for (int i = 0; i < n; i++) {
    if (!m[i]) return i;
  }
  return n;
}
long long C(long long n,long long r)
{
    long long N=1,R=1;
    if(r>n or r<0)return 0;
    if(n==r or r==0)return 1;
    for(long long i=1;i<=n;i++) N=N*i%M;
    for(long long i=1;i<=r;i++) R=R*i%M;
    for(long long i=1;i<=n-r;i++) R=R*i%M;
    return (N*powM(R,M-2))%M;
}
ll fact_dp(int n)

{

    if (n >= 0) 

    {

        result[0] = 1;

        for (int i = 1; i <= n; ++i) 

        {

            result[i] = i * result[i - 1];

        }

        return result[n];

    }

}
int binarySearch(int arr[], int l, int r, int x,int n) 
{ 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if ((arr[m] <= x) and ( (arr[m+1]>x) or (m+1==n)) /*and (m>0)*/) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 
}
void precompute(int s[], int n, int l[][MAX],  
                                 int r[][MAX]) 
{ 
    l[s[0]][0] = 1; 
  
    // Precompute the prefix 2D array 
    for (int i = 1; i < n; i++) { 
        for (int j = 0; j < MAX_CHAR; j++)  
            l[j][i] += l[j][i - 1];         
  
        l[s[i]][i]++; 
    } 
  
    r[s[n - 1]][n - 1] = 1; 
  
    // Precompute the Suffix 2D array. 
    for (int i = n - 2; i >= 0; i--) { 
        for (int j = 0; j < MAX_CHAR; j++)  
            r[j][i] += r[j][i + 1];        
  
        r[s[i]][i]++; 
    } 
}
// Find the number of palindromic subsequence of  
// length k 
int countPalindromes(int k, int n, int l[][MAX],  
                                   int r[][MAX]) 
{ 
    int ans = 0; 
  
    // If k is 1. 
    if (k == 1) { 
        for (int i = 0; i < MAX_CHAR; i++)  
            ans += l[i][n - 1];   
        return ans; 
    } 
  
    // If k is 2 
    if (k == 2) { 
  
        // Adding all the products of prefix array 
        for (int i = 0; i < MAX_CHAR; i++)              
            ans += ((l[i][n - 1] * (l[i][n - 1] - 1)) / 2); 
        return ans; 
    } 
  
    // For k greater than 2. Adding all the products 
    // of value of prefix and suffix array. 
    for (int i = 1; i < n - 1; i++)  
        for (int j = 0; j < MAX_CHAR; j++)              
            ans += l[j][i - 1] * r[j][i + 1];   
  
    return ans; 
}
//cycle detecttion in undirectedgraph
void dfs(int i,int p=0){
  vis[i]=1;
  s.push(i);
  D[i]=s.size();
  for(auto x:a[i]){
    if(vis[x]==0){
      dfs(x,i);
    }
    else {
      if(D[i]-D[x]+1<=k and D[i]-D[x]+1>=3){
        //enter a cycle
        cout<<2<<"\n";
        cout<<D[i]-D[x]+1<<"\n";
        int z=D[i]-D[x]+1;
        while(z--)
          {cout<<s.top()<<" ";s.pop();}
        exit(0);
      }
    }
  }
  for(auto x:a[i]){
      if(d.count(i)==0)d.insert(x);
  }
  s.pop();
}
// const int N1 = 1e5;  // limit for array size
// int n;  // array size
// int t[2 * N1];

// void build() {  // build the tree
//   for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
// }

// void modify(int p, int value) {  // set value at position p
//   for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
// }

// int query(int l, int r) {  // sum on interval [l, r)
//   int res = 0;
//   for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
//     if (l&1) res += t[l++];
//     if (r&1) res += t[--r];
//   }
//   return res;
// }
// ll A[N],r[N];
// bool cmp(int a, int b) {
//     return(A[a] == A[b] ? (a < b) : (A[a] > A[b]));
// }
//returns number of elements with nth bit set in v
void solve(){
    // cin>>n;
    // for (int i = 0; i < n; ++i)
    // {
    //     cin>>t[n+i];
    // }
    // build();
    // string s;cin>>s;std::map<char, set<char> > m;
    // for (int i = 0; i < s.length(); ++i)
    // {
    //     if(i==0){m[s[i]].insert(s[i+1]);continue;}
    //     if(i==s.length()-1){m[s[i]].insert(s[i-1]);continue;}
    //     m[s[i]].insert(s[i-1]),m[s[i]].insert(s[i+1]);
    // }
    // for(auto i: m){
    //     for (auto j:i.S)
    //     {
    //         // cout<<j<<" ";
    //         {if(!m[j].count(i.F))cout<<"NO\n";return;}
    //     }
    //     cout<<"\n";
    // }
}
int main()
{   
    ibs;cti;
    // int t;cin>>t;
    // while(t--)
    solve(),cout<<"\n";
    return 0;
}
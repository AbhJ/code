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
long long C(long long n,long long r)
{
    long long N=1,R=1;
    for(long long i=1;i<=n;i++) N=N*i%M;
    for(long long i=1;i<=r;i++) R=R*i%M;
    for(long long i=1;i<=n-r;i++) R=R*i%M;
    return (N*powM(R,M-2))%M;
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
   string s;cin>>s;int ans=0,st=-1,en=-1;
   for (int i=0;i<s.length();i++)
   {
      if(s[i]=='0')
      while(s[i]=='0')ans++,i++;
   }
   int i=0;
   if(s.length()==1){cout<<0;return;}
   while(s[i]=='0')i++,ans--;
   // if(s[0]=='0' and ans)ans--;
   if(i!=s.length()){i=s.length()-1;
   while(s[i]=='0')i--,ans--;}
   // if(s.back()=='0' and ans)ans--;
   cout<<ans;
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--)
    solve(),cout<<"\n";
    return 0;
}
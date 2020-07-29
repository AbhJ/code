#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
using namespace std;//coded by abhijay mitra
const int N=2e6+3;
const ll M = 1000000007; // modulo
#define F first
#define S second
#define MAX 100 
#define MAX_CHAR 26
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
int A[N];
string solve(string s){
 int n=s.length(),i=1,j=0;
 for (; i < n; ++i)
 {
   while(j and (s[i]-s[j]))
    j=A[j-1];
   if(s[i]==s[j])j++;
   A[i]=j;
 }
 return s.substr(0,j);
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--){
      string s,r;cin>>s;int n=s.length();int j=n-1,i=0;
      while(i<j and (s[i]==s[j]))++i,--j;
      string hectic=s.substr(i,j-i+1);r=hectic;
      reverse(r.begin(), r.end());
      string s1=solve(hectic+'A'+r),s2=solve(r+'#'+hectic);
      if(s1.length()<s2.length())s1=s2;
      cout<<s.substr(0,i)+s1+s.substr(j+1);
      cout<<"\n";
    }
    return 0;
}
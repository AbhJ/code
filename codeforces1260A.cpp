#include <bits/stdc++.h>
#define ll long long
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define pb push_back
#define N 400015
ll y=0;
struct table{
    int val,id;
};
bool cmp(table a,table b)
{
    return a.val>b.val;
}
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
void split(ll x, ll n) 
{ 
  
// If we cannot split the  
// number llo exactly 'N' parts 
// if(x < n) 
// cout<<"-1"<<" "; 
  
          
  
    // If x % n == 0 then the minimum  
    // difference is 0 and all  
    // numbers are x / n 
    if (x % n == 0) 
    { 
        for(ll i=0;i<n;i++) 
        // cout<<(x/n)<<" "; 
        y+=(x/n)*(x/n);
    } 
    else
    { 
  
        // upto n-(x % n) the values  
        // will be x / n  
        // after that the values  
        // will be x / n + 1 
        ll zp = n - (x % n); 
        ll pp = x/n; 
        for(ll i=0;i<n;i++)  
        { 
  
            if(i>= zp) 
            /*cout<<(pp + 1)<<" ";*/ y+=(pp+1)*(pp+1);
            else
            /*cout<<pp<<" "; */y+=pp*pp;
        } 
    } 
}
int main()
{
    ibs;cti;int c,s;int n;cin>>n;
    while(n--){
        cin>>c>>s;y=0;
        if(c<=s){
            split(s,c);
            cout<<y<<"\n";
        }
        else cout<<(ll)s<<"\n";

        
    }
    return 0;   
}
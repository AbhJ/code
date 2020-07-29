#include <bits/stdc++.h>
#define ll long long int
#define N 1000000
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
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
// Returns factorial of n 
ll fact(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
}
ll nCr(ll n, ll r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 
int main()
{
    ibs,cti;
    int t;cin>>t;
    while(t--){
        int n1;cin>>n1;string a1,b1;cin>>a1>>b1;
        bitset<N> A(a1), B(b1);
        int a= A.count(),b=B.count();
        if(a==b and a==n1){cout<<1<<"\n";continue;}
        int best=abs(b-a),worst=0;
        sort(a1.begin(), a1.end()),sort(b1.begin(), b1.end(), greater<char>()); 
        bitset<N>A1(a1),B1(b1);A1^=B1;worst= A1.count();
        ll sum=0;
        for (int i = best; i <=worst ; i+=2)
            sum+=(nCr(n1,i)%M);
        cout<<sum%M<<"\n";
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 1000100
#define M 1000000007
ll binomialCoeff(ll n, ll k) 
{ 
    ll C[n + 1][k + 1]; 
    ll i, j; 
  
    // Caculate value of Binomial Coefficient 
    // in bottom up manner 
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            // Base Cases 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
  
            // Calculate value using previously 
            // stored values 
            else
                C[i][j] = (C[i - 1][j - 1] + 
                          C[i - 1][j])%M; 
        } 
    }
    return C[n][k]; 
}
int main()
{
    ibs;cti;
    	ll n,m;cin>>n>>m;
        cout<<binomialCoeff(n+2*m-1,2*m)%M<<"\n";
    return 0;
}
#include <bits/stdc++.h>
#define ll long long int
#define N 1000009
#define M 1000000007
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;
    int t;cin>>t;cout<<"\n";
    while(t--){
        int n;cin>>n;ll k;cin>>k;std::vector<ll> v(n,0);ll gcd=0;cin>>v[0];
        gcd=v[0];
        for(int i=1;i<n;i++){
            cin>>v[i];gcd=__gcd(gcd,v[i]);
        }
        ll prime_fac=1;
        for(ll i=2; i<=sqrt(gcd); i++){
            while(gcd%i==0){
                gcd/=i;
                prime_fac=max(prime_fac, i);
            }
        }
        prime_fac=max(prime_fac, gcd);//we've got lagest prime factor
        if (prime_fac>k)
            cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
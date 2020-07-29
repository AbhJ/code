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
    #define cot cout.tie(0)//solved by abhijay mitra
    using namespace std;int v[N];
    #define watch(x) cout << (#x) << " is " << (x) << endl
//     #include <bits/stdc++.h>
// using namespace std;
// #define M 1000000007
// #define ll long long
// #define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    //t=1;
    for(int ii=0; ii<t; ii++){
        ll n;
        cin>>n;
        ll q=n*n;
        ll p=0;
        ll a=sqrt(n);
        for(int i=1; i<=a; i++){
            p+=(n/i);
        }
        p*=2;
        p-=(a*a);
        ll gcd=__gcd(p,q);
        cout<<p/gcd<<"/"<<q/gcd<<"\n";
    }
    
    return 0;
}
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
    #define cot cout.tie(0)//solved by abhijay mitra
    using namespace std;
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main(){
        ibs;cti; 
        int T;cin>>T;cout<<"\n";
        while(T--){
            double n,k;cin>>n>>k;
            double ans=2;
            ans+=2*(n-1)*(k-1)/k;
            cout<<fixed<<setprecision(10)<<ans<<endl;
        }
        return 0;
    }
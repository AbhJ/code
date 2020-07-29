#include <bits/stdc++.h>
#define ll long long int
#define N 100009
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
    ibs;cti;int t;cin>>t;
    while(t--){
    	int n;cin>>n;std::vector<ll> v(n);bool check=0;ll s=0,x=0;
    	for (int i = 0; i < n; ++i){
	    	cin>>v[i];s+=v[i];x=x^v[i];
    	}ll good = (1LL<<50) + s%2;x^=good;s+=good;x*=2;
    		cout<<3<<"\n"<<good<<" "<<(x-s)/2<<" "<<(x-s)/2<<"\n";
    }return 0;   
}
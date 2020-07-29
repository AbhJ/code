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
    	int n;cin>>n;std::vector<ll> v(n);bool check=0;
    	for (int i = 0; i < n; ++i){
	    	cin>>v[i];if((abs(v[i]-v[i-1])>1) and i!=0 and check=0){
	    		check=1;cout<<"YES\n"<<i<<" "<<i+1;
	    	}
    	}if(!check)cout<<"NO";cout<<"\n";
    }return 0;   
}
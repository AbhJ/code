#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define M 10000007
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;std::vector<ll> a(m+1),b(m+1);
        for (int i = 1; i <= m; ++i)cin>>a[i];for (int i = 1; i <= m; ++i)cin>>b[i];
        ll result=0;
	    for (int i = 1; i <= m; ++i)
	    {
	    	for (int j = 1; j <= m; ++j)
	    	{
	    		std::vector<ll> fib(max(2,n)+1);
	    		fib[1]=a[i];fib[2]=b[j];
	    		for(int k=3;k<=n;k++)fib[k]=fib[k-1]+fib[k-2];
	    		result+=fib[n];result%=M;
	    	}
	    }
	    cout<<result%M<<"\n";
    }return 0;   
}
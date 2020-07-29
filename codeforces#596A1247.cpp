#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define N 100000 
#define M 1000000007
int main()
{   
    ibs;cti;
	int t;cin>>t;
	while(t--){
		int n,k,d;cin>>n>>k>>d;
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i)
			cin>>v[i];
		int m=INT_MAX;
		for (int i = 0; i < n-d+1; ++i)
		{
			int count=1;std::vector<int> q;q.pb(v[i]);
			for(int j=i+1;j<i+d;j++){
				// if(v[j]!=v[j-1]){
					int i1;
					for (i1 = 0; i1 < q.size(); ++i1)
					{
						if(v[j]==q[i1])break;
					}
					if(i1==q.size())count++,q.pb(v[j]);
					// cout<<count<<"\n";
				// }
			}
			m=min(m,count);
		}
		cout<<m<<"\n";
	}
    return 0;
}
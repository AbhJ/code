#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
int main()
{   
    ibs;cti;
 	int n,K;cin>>n>>K;std::map<string, int> m;
 	std::vector<string> v(n);
 	for (int i = 0; i < n; ++i){
	 	cin>>v[i];
	 	m[v[i]]++;
 	}
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		for(int j=i+1;j<n;j++){
			string s;for(int k=0;k<K;k++){
				if(v[i][k]==v[j][k])s+=v[i][k];
				else s+=('S'+'E'+'T'-v[i][k]-v[j][k]);
			}
			ans+=m[s];
		}
	}
	cout<<ans/3<<"\n";
    return 0;
}
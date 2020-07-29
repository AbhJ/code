#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
const int N=2e5+3,A=1e6+3;
int n,k,d,a[N],b[A],c,ans;
int main()
{   
    // ibs;cti;
	int t;cin>>t;
	while(t--){
		cin>>n>>k>>d;
		ans=d;c=0;//ans can't be more than n
		//c is count of different numbers
		for(int i=1;i<=n;i++){
		  cin>>a[i];//filling up the a[n] input array
		  if(!b[a[i]])c++;//if that element hasn't been encountered before,it's a new element
		  b[a[i]]++;
		  if(i>d){
			b[a[i-d]]--;//sliding window left it
			if(!b[a[i-d]])c--;//no count left in sliding window,so we lose that number
		  }
		  if(i>=d)ans=min(ans,c);//window is complete
		}
		for(int i=1;i<=n;i++)b[a[i]]=0;
		cout<<ans<<"\n";
	}
    return 0;
}
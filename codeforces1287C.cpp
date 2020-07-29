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
	int dp[110][110][2];
 	int n;cin>>n;std::vector<int> v(n+1,0);
 	for (int i = 1; i <= n; ++i)
 	{
 		cin>>v[i];
 	}
	for(int i=0;i<110;i++) 
		for(int j=0;j<110;j++) 
			dp[i][j][0]=dp[i][j][1]=1e9;        
	dp[0][0][1]=dp[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(v[i]%2||v[i]==0)
			{
				dp[i][j][1]=min(dp[i-1][j][0]+1,dp[i-1][j][1]);
			}
			if(v[i]%2==0)
			{
				dp[i][j][0]=min(dp[i-1][j-1][0],dp[i-1][j-1][1]+1);
			}
		}
	}
    cout<<min(dp[n][n/2][0],dp[n][n/2][1])<<"\n";
    return 0;
}
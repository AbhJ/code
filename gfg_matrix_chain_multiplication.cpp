#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
const long M = 1000000007; // modulo
int mat(std::vector<int> v,int n){
  int dp[n+1][n+1];//dp i, j is min numb of operations for multiplying ith matr until jth mat
  for (int i = 0; i < n; ++i)
    dp[i][i]=0;
  for (int L = 2; L < n; ++L)//filling up the matrix m length wise
  {
    for (int i = 1; i < n-L+1; ++i)
    {
      int j=i+L-1;dp[i][j]=INT_MAX;
      for (int k = i+1; k <= j; ++k)
        dp[i][j]=min(dp[i][k-1]+dp[k][j]+v[i-1]*v[k-1]*v[j],dp[i][j]);
    }
  }
  return dp[1][n-1];
}
int main()
{   
    ibs;cti;
    int t;cin>>t;
    while(t--){
      int n;cin>>n;std::vector<int> v(n);
      for (int i = 0; i < n; ++i)cin>>v[i];
      cout<<mat(v,n)<<"\n";
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
using namespace std;//coded by abhijay mitra
const int N=2e5+3;
int m[2][N];//the grid
int main()
{   
    ibs;cti;
	int n,q,b=0,d;cin>>n>>q;
	while(q--){
		int x,y;cin>>x>>y;x--,y--;
		if(m[x][y])d=1,m[x][y]=0;else d=-1,m[x][y]=1;//if that coordinate is lava
		for (int i = -1; i <= 1; ++i)
		{
			if(y+i >= 0 and y+i < n and m[1-x][i+y] == 1)
				b+=d;
		}
		if(b)cout<<"NO\n";
		else cout<<"YES\n";
	}
    return 0;
}
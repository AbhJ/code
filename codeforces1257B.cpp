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
    	int x,y;cin>>x>>y;
        if(((x==1) and (y!=1)) or ((x<4) and (x>1) and (y>3))){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }
    return 0;
}
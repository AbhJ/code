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
    	int a,b;cin>>a>>b;
        if(b==a)cout<<b<<1<<" "<<a<<2;
        else if(b==a+1)cout<<a<<9<<" "<<b<<0;
        else if(a+1==b*10)cout<<a<<9<<" "<<b*10<<0;
        else cout<<"-1";
        cout<<"\n";
    return 0;
}
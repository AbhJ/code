#include <bits/stdc++.h>
#define ll long long
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define pb push_back
#define N 400015
struct table{
    int val,id;
};
bool cmp(table a,table b)
{
    return a.val>b.val;
}
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs;cti;int n,k;cin>>n>>k;
    for(int i=k-1;i>0;i--)/*//is the mod x%k{*/{
        if(n%i) continue;
        ll x=n*k/i+i;
        if((x/k)*(x%k)==n){
            cout<<x<<"\n";break;
        } 
    }
    return 0;   
}
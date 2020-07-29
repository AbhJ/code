#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
#define N 1000100
int main()
{
    ibs;cti;int n,l=0,r=0;string s;
    cin>>n;cin>>s;
    for (int i = 0; i < n; ++i)
    {
        if(s[i]=='L')l++;
        else r++;
    }
    cout<<r+l+1<<"\n";
    return 0;
}
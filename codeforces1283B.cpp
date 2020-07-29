#include <bits/stdc++.h>
    #define ll long long int
    #define pb push_back
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    using namespace std;//coded by abhijay mitra
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;int T;cin>>T;
        while(T--){
                int n,k;cin>>n>>k;
                int a=n/k;int x=k/2;//number of kids with a+1
                if(x*(a+1)+a*(k-x)>n)
                    x=n-a*k;
                cout<<x*(a+1)+(k-x)*a<<"\n";
        }return 0;
    }
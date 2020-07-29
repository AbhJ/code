#include <bits/stdc++.h>//DYNAMO
#define ll long long int
#define pb push_back
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
using namespace std;//coded by abhijay mitra
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;ll a;cin>>a;
        ll s=5,c=1,b,d,f=9;
        for (int i = 0; i < n-1; ++i)
        {
            f*=10;f+=9;
        }
        for (int i = 0; i < n; ++i)
        {
            s*=10;
        }
        /*if(a>f/2)*/s=f+2*a+abs(f-a)+2;/*else s=2*f+a+2;*/cout<<s<<"\n";cout.flush();
        cin>>b;c=min(s-a-b-f-1,f);cout<<c<<"\n";cout.flush();cin>>d;
        cout<<s-a-b-c-d<<"\n";cout.flush();
        int check;cin>>check;
        if(check==-1){cout<<"Error";cout.flush();return 0;}
    }
    return 0;   
}
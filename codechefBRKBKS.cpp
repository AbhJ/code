#include <bits/stdc++.h>
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
        int s,x,y;cin>>s;std::vector<int> v(3);
        for (int i = 0; i < 3; ++i)cin>>v[i];cout<<"\n";
        if(v[0]+v[1]+v[2]<=s){x=1;}
        else if(v[0]+v[1]<=s){x=2;}
        else if (v[0]<=s){x=3;}
        reverse(v.begin(), v.end());
        if(v[0]+v[1]+v[2]<=s){y=1;}
        else if(v[0]+v[1]<=s){y=2;}
        else if (v[0]<=s){y=3;}
        cout<<min(x,y)<<"\n";
    }
    return 0;   
}
    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    #define N 100000
    using namespace std;//coded by abhijay mitra
    ll c[N];
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;
        int n,k;cin>>n>>k;string s;
        cin>>s;std::vector<char> c(k);
        for (int i = 0; i < k; ++i)
            cin>>c[i];
        int x=0;ll y=0,i;
        for (i = 0; i < n; ++i)
        {
            x=0;
            for(int j=0;j<k;j++)
                if(s[i]==c[j]){
                    x=1;break;
                }
            int pos=i,z=0;
            if(x){ 
                while(pos<n){
                    pos++;z=0;
                    for(int pos1=0;pos1<k;pos1++)
                        if(s[pos]==c[pos1]){
                        z=1;break;
                    }
                    if(z==0)
                        break;
                }
            }
            y+=(pos-i)*(pos-i+1)/2;
            i=pos;
        }
        cout<<y<<"\n";
        return 0;   
    }
    #include <bits/stdc++.h>
    #define ll long long
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    #define pb push_back
    #define N 200015
    using namespace std;//coded by abhijay mitra
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;ll t,n;string s,c;cin>>t;
        while(t--){
            cin>>s>>c;
            string x="";n=s.length();
            //=s;sort(x.begin(), x.end());bool y=1;int dude=-1
            for (int i = 0; i < n; ++i)
            {
                for (int j = i+1; j < n; ++j)
                {
                    string test=s;swap(test[i],test[j]);bool c1=0;
                    if(min(test,c)==test){
                        for (int i1 = 0; i1 < n and i1<c.length(); ++i1)
                        {
                            for (int j1 = 0; j1 < i1; ++j1)
                            {
                                if(test[i1]<c[i1] and test[j1]==c[j1]){c1=1;break;}
                            }
                            if(c1==1)break;
                        }
                        if(c1==1){x=max(x,test);}
                    }
                         
                }
            }
            if(x!="")
                cout<<x;
            else if(min(s,c)==c)cout<<"---";
            else cout<<s;
            cout<<"\n";
        }
        return 0;   
    }
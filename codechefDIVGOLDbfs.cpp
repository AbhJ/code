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
        ibs;cti;ll t,n;string s;cin>>t;
        while(t--){
            cin>>n>>s;
            string x=s;sort(x.begin(), x.end());bool y=1;int dude=-1;
            for (int i = 0; i < n; ++i)
            {
                if((x[i]==s[i] or y==0)){
                    if(i!=dude)cout<<s[i];
                }
                else if(x[i]<s[i]){cout<<x[i];y=0;
                    for(int i1=n-1;;i1--){
                        if(s[i1]==x[i]){
                            dude=i1;i--;break;
                        }
                    }
                }
                else{
                    cout<<x[i];y=0;
                    for(int i1=i+1;;i1++){
                        if(s[i1]==x[i]){
                            dude=i1;i++;break;
                        }
                    }
                }
            }
            cout<<"\n";
        }
        return 0;   
    }
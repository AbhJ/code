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
                n=s.length();int pos;bool check=0;char ch;
                // if(s<c){cout<<s<<"\n";continue;}
                for (int i = 0; i < n; ++i)
                {
                    ch=s[i];
                    for (int j = i+1; j < n; ++j)
                        if(ch>=s[j]){//finding smallest element to right that is smaller than s[i]
                            check=1;
                            ch=s[j];
                            pos=j;
                        }
                    if(check and s[pos]<s[i]){
                        swap(s[i],s[pos]);
                        break;
                    }else check=0;
                }
                if(s<c)cout<<s<<"\n";
                else cout<<"---"<<"\n";
            }
            return 0;   
        }
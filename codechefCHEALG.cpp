#include <bits/stdc++.h>
    #define ibs ios_base::sync_with_stdio(false)
    #define cti cin.tie(0)
    using namespace std;//coded by abhijay mitra
    #define watch(x) cout << (#x) << " is " << (x) << endl
    int main()
    {
        ibs;cti;int T;cin>>T;
        while(T--){
            string s;cin>>s;int x=0,count=1,i;
            for (i = 0; i < s.length()-1; ++i)
            {
                if(s[i]!=s[i+1] ){
                    x+=count-2;
                    if(count>=10){
                        if(count>=1000)x-=3;
                        else if(count>=100)x-=2;
                        else if(count>=10)x--;
                    }
                    count=1;
                }
                else count++;
            }
            if(s[i]!=s[i+1] ){
                    x+=count-2;
                    if(count>=10){
                        if(count>=1000)x-=3;
                        else if(count>=100)x-=2;
                        else if(count>=10)x--;
                    }count=1;
                }
            if(x>0)cout<<"YES\n";
            else cout<<"NO\n";
        }return 0;
    }
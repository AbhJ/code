        #include <bits/stdc++.h>
        #define ll long long int
        #define N 100000
        #define M 1000000007
        #define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
        #define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
        #define po pop_back
        #define pb push_back
        #define lb lower_bound
        #define ub upper_bound
        #define ibs ios_base::sync_with_stdio(false)
        #define cti cin.tie(0)
        #define cot cout.tie(0)//solved by abhijay mitra
        using namespace std;bool a[26];int num[10];
        #define watch(x) cout << (#x) << " is " << (x) << endl
        int main(){
            // ibs;cti; 
            int T;
            cin>>T;
            while(T--){
                    cout<<"\n";
                    for (int i = 0; i < 10; ++i)
                        num[i]=0;
                    for (int i = 0; i < 26; ++i)
                    {
                        a[i]=0;
                    }
                    int n,k;ll m;string s;
                    cin>>s;bool check=0;
                    char c;
                    for(ll i=0;i<s.length();i++){
                        c=s[i];
                        if (num[c-'0']<2)
                            num[c-'0']++;
                    }
                    if (num[6]!=0 and num[5]!=0)
                    {
                        a[0]=1;
                    }
                     if (num[6]==2)
                    {
                        a[1]=1;
                    }
                     if (num[6]!=0 and num[7]!=0)
                    {
                        a[2]=1;
                    }
                     if (num[6]!=0 and num[8]!=0)
                    {
                        a[3]=1;
                    }
                     if (num[6]!=0 and num[9]!=0)
                    {
                        a[4]=1;
                    }
                     if (num[7]==2)
                    {
                        a[12]=1;
                    }
                     if (num[8]==2)
                    {
                        a[23]=1;
                    }
                     if (num[9]!=0 and num[0]!=0)
                    {
                        a[25]=1;
                    }
                    for (int i = 7; i < 9; ++i)//70to89 except 77 and 88
                    {
                        for (int j = 0; (j<10) ; ++j)
                        {
                            if (!(j-i))
                            {
                                continue;
                            }
                            if(num[i]==0||num[j]==0) continue;
                            int x=i*10+j;
                            a[x-65]=1;
                        }
                    }
                    for (int i = 0; i < 26; ++i)
                        if(a[i])printf("%c",'A'+i);
                }
            return 0;
        }
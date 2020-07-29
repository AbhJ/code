#include <bits/stdc++.h>
#define ll long long int
#define N 1000000
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
using namespace std;int n=0;
string convertToString(char* a, int size) 
{ 
    int i; 
    string s = ""; 
    for (i = 0; i < size; i++) { 
        s = s + a[i]; 
    } 
    return s; 
} 
void addo(string A,string B){
    while(1){
        while (A[0]=='0' and B[0]=='0')
        {
            A.erase (A.begin(), A.begin()+1);
            B.erase (B.begin(), B.begin()+1);
        }
        ll size=A.length(); bool x=0;
        for (ll i = 0; i < size; ++i)
            if(B[i]!='0'){
                x=1;break;
            }
        if (x==0)
            break;
        char U[size+1],V[size+1];U[0]='0';V[size]='0';
        for (int i = 0; i < size; ++i){
            U[i+1] = ((A[i]-'0') ^ (B[i]-'0')) + '0'; 
            
        }
        for (int i = 0; i < size; ++i)
            V[i] = ((A[i]-'0') & (B[i]-'0')) + '0'; 
        A = convertToString(U,size+1);
        B = convertToString(V,size+1);
        // cout<<A<<"\n"; cout<<B<<"\n";        
        n++;
        ll count1=0,index=0;
        for (int i = 0; i < size+1; ++i)
            if (B[i]=='1'){
                count1++;index=i;
            }
        if (count1==1)
        {
            for (int i = index; A[i]=='1'; --i)
            {
                n++;
            }
            n++;
            break;
        }
    }
    // cout<<A<<"\n"; cout<<B<<"\n";
}
#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    ibs,cti;
    int t;cin>>t;string a,b;cout<<"\n\n";
    while(t--){
        cin>>a>>b;n=0;ll size;
        // the below snippets are to make length of a and b same
        if (a.length()>b.length())
        {
           size=a.length()-b.length();
           string B="0";
           for (int i = 0; i < size-1; ++i)
               B.pb('0');
           b=B+b;
        }
        if (b.length()>a.length())
        {
           size=-a.length()+b.length();
           string A="0";
           for (int i = 0; i < size-1; ++i)
               A.pb('0');
           a=A+a;
        }
        size=a.length();
        // cout<<"\n\n"<<a<<"\n"<<b<<"\n";
        addo(a,b);cout<<n<<"\n";
    }
    return 0;
}
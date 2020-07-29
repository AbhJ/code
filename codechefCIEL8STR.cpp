#include <iostream>
#include<string>
using namespace std;
int main() {
    string str;
    cin>>str;
    int len=str.length();
    long long int ans=0;
    for(int i=0; i<len; i++)
    {
        int k=str[i]-'0';
        if(k%8==0)
        {
            ans++;
        }
    }
    for(int i=1; i<len; i++)
    {
        int k=(str[i-1]-'0')*10+(str[i]-'0');
        if(k%8==0 && str[i-1]!='0')
        {
            ans++;
        }
    }
    int nonzeroes=0;
    for(int i=2; i<len; i++)
    {
        int k=(str[i-2]-'0')*100+(str[i-1]-'0')*10+(str[i]-'0');
        if(str[i-2]!='0')
        {
            nonzeroes++;
        }
        if(k%8==0)
        {
            ans+=nonzeroes;
        }
    }
    cout<<ans<<endl;    
    return 0;
}
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=1001000,mo=1000000007;
typedef long long ll;
using namespace std;
ll num[N];
char c[N];
int T,nex[N];
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",c+1);int n=strlen(c+1);
        memset(num,0,sizeof num);
        num[1]=1;
        int j=0;
        fo(i,2,n)
        {
            while (j&&c[i]!=c[j+1]) j=nex[j];
            if (c[i]==c[j+1]) j++;
            nex[i]=j;
            num[i]=num[j]+1;
        }
        j=0;
        ll ans=1;
        fo(i,2,n)
        {
            while (j&&c[i]!=c[j+1]) j=nex[j];
            if (c[i]==c[j+1]) ++j;
            while (j>(i>>1)) j=nex[j];
            ans=ans*(num[j]+1)%mo;
        }
        printf("%lld\n",ans);
    }
}
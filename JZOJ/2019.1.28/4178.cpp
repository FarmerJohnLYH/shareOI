#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=1001000;
int a[N],b[N],c[N],d[N],n,m,t,sg,ans;
int main()
{
//	freopen("D:/LiuYuanHao/a1.in","r",stdin);
    scanf("%d%d",&m,&n);
    fo(i,1,n) scanf("%d",&a[i]);
    if(a[n]==m-1)
	{
		fd(i,n,1)if(a[i-1]+1!=a[i])
		{
			t=i;
			break;
		}
        printf("%d",n-t+1);
		return 0;
    }
    a[n+1]=m-1;a[0]=-1;
    fd(i,n,1)
    {
        int l=i;t+=a[i+1]-a[i]-1;
        while (a[l-1]+1==a[l]) l--;
        if(t&1) b[++b[0]]=i-l+1;
        else 
		if(t)
		{
            c[++c[0]]=i-l+1;
            if(a[i]+2==a[i+1]) d[c[0]]=b[b[0]];
        }
        i=l;
    }
    fo(i,1,b[0]) sg^=b[i];
    fo(i,1,b[0])
		if((b[i]^sg)<=b[i]) ++ans;
    fo(i,1,c[0])
		if((d[i]^sg)<=d[i]+c[i]&&(d[i]^sg)>d[i]) ++ans;
    if(!sg) ans=0;
	printf("%d",ans); 
	return 0;
}












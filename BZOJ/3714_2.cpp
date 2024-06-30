#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=2020,M=N*N;
struct edge{
    int x,y,v;
}e[M];
bool cmp(edge x,edge y)
{
    return(x.v<y.v);
}
int n,m;
int f[N];
int gf(int x)
{
    return(f[x]==x)?x:(f[x]=gf(f[x]));
}
int read()
{
    int x=0,flag=1;
    char ch=getchar();
    while(!(ch=='-'||(ch>='0'&&ch<='9'))) ch=getchar();
    if(ch=='-') flag=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return(x*flag);
}
int main()
{
//    freopen("D:/LiuYuanHao/a1.in","r",stdin);
    n=read();
    fo(i,1,n)
    {
        fo(j,i,n)
        {
            e[++m].x=i,e[m].y=j+1;
            e[m].v=read();
        }
        f[i]=i;
    }
    ++n;f[n]=n;
    sort(e+1,e+1+m,cmp);
    ll ans=0;
	int tot=0,fx,fy;
    fo(i,1,m)
        if((fx=gf(e[i].x))!=(fy=gf(e[i].y)))
        {
            f[fx]=fy;
            ans=ans+e[i].v;
            if(++tot==n-1)
				break;
	
	    }
    printf("%lld\n",ans);
    return 0;
}

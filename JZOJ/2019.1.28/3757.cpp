#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,nm,q,top;
ll a,b,c,d;
int x[25000005],t[25000005],up[5005],down[5005],ans[10005];
void add(int a,int b)
{
    for(int i=1;i<=n;i++)
        if(i<a)up[i]=min(b,up[i]);
        else if(i>a)down[i]=max(b,down[i]);
}
int main()
{
    memset(up,127/3,sizeof(up));
    x[0]=read();a=read();b=read();c=read();d=read();
    n=read();m=read();q=read();nm=n*m;
    for(int i=1;i<=nm;i++)
            x[i]=(x[i-1]*(a*x[i-1]+b)+c)%d,t[i]=i;
    for(int i=1;i<=nm;i++)
        swap(t[i],t[(x[i]%i)+1]);
    for(int i=1;i<=q;i++)
    {
        int x=read(),y=read();
        swap(t[x],t[y]);
    }
    for(int i=1;i<=nm;i++)x[t[i]]=i;
    int a,b;
    for(int i=1;i<=nm;i++)
    {
        if(x[i]%m)a=x[i]/m+1;
        else a=x[i]/m;
        b=x[i]%m;if(!b)b+=m;
        if(b<=up[a]&&b>=down[a])
        {
            add(a,b);
            ans[++top]=i;
            if(top==n+m-1)break;
        }
    }
    for(int i=1;i<=top;i++)
    {
        printf("%d",ans[i]);
        if(i!=top)printf(" ");
    }
    return 0;
}
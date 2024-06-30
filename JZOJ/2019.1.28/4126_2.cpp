#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int mo=9699667,N=4000400,q1=9473;
int n,m,d,s0,t0,sum;
char s[N],t[N];
int ct[mo+10],qm[N],ny[N];
int h[N];
int ans=0;
int qsm(int x,int y)
{
    int rt=1;
    fo(i,0,30)
    {
        if(y<(1<<i))return(rt);
        if(y&(1<<i)) rt=1ll*rt*x%mo;
        x=1ll*x*x%mo;
    }
    return(rt);
}
int hs(char *x) /*Len=m*/
{
    int rt=0;
    fd(i,m,1) rt=(1ll*rt*q1+(x[i]-'a'+1))%mo; 
    return rt;
}
int p[N];
int get(int x,int x0,int y,int y0)
{
    return(((1ll*(h[y+y0]-h[y]+mo)*ny[n*s0-(y+y0)]%mo)*qm[x0]%mo+1ll*(h[x+x0]-h[x]+mo)*ny[n*s0-(x+x0)]%mo)%mo);
}
void kmp(char *s/*len=d*/,char *t/*n-d*/,int pl)
{
    int ls=d,lt=n-d;
    int j=0;p[1]=0;
    fo(i,2,lt)
    {
        while(t[i]!=t[j+1]&&j)j=p[j];
        if(t[i]==t[j+1])++j;
        p[i]=j;
    }
    j=0;
    fo(i,1,ls)
    {
        while(s[i]!=t[j+1]&&j)j=p[j];
        if(s[i]==t[j+1])++j;
        if(j==lt)
        {
            //s[i-lt+1..i]==t[]
            int tp=get(pl,i-lt,pl+i+lt-2,m-(i-lt));
            ans+=ct[tp];
        //5150039
        }
    }
}
int main()
{
    freopen("D:/LiuYuanHao/b.in","r",stdin);
    scanf("%d%d%d%d",&s0,&t0,&n,&m);
    fo(i,1,s0)scanf("%s",s+1+(i-1)*n);
    fo(i,1,t0)scanf("%s",t+1+(i-1)*m);
    if(n<m)swap(n,m),swap(s,t),swap(s0,t0);
    h[n*s0+1]=1;
    fd(i,n*s0,1) h[i]=(1ll*h[i+1]*q1+s[i]-'a'+1)%mo;
    qm[0]=1;fo(i,1,sum=(n*s0+m*t0)) qm[i]=(1ll*qm[i-1]*q1)%mo;
    ny[sum]=qsm(qm[sum],mo-2);fd(i,sum-1,0) ny[i]=(1ll*ny[i+1]*q1)%mo;
    d=(n+m)>>1;
    fo(i,1,t0) 
    {
        ++ct[hs(t+(i-1)*m)];
    }
    fo(i,1,s0)
        kmp(s+(i-1)*n,s+(i-1)*n+d,(i-1)*n);
    printf("%d\n",ans);
    return 0;
}











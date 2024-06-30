#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x),asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
// const int N=110*110*3*2;
const int N=500500*3;
int nx[N],ls[N],to[N],fw[N],cur[N];
int d[N],gp[N];
int S,T,ans;
int tot=1;
int n,m,pt;
int hh(int x,int y){return((x-1)*m+y);}
void link(int x,int y,int v)
{
    (++tot)[to]=y,tot[nx]=x[ls],cur[x]=ls[x]=tot,fw[tot]=v;
    (++tot)[to]=x,tot[nx]=y[ls],cur[y]=ls[y]=tot,fw[tot]=0;
}
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int nw(int x,int f)
{
    if(x==T)return f;
    int hv=0;
    for (int tmp=x[cur];tmp;tmp=tmp[nx])
    {
        int t=tmp[to];
        if(tmp[fw]>0&&d[t]+1==d[x])
        {
            x[cur]=tmp;
            int vt=nw(t,min(f-hv,tmp[fw]));
            hv+=vt,fw[tmp]-=vt,fw[tmp^1]+=vt;
            if(hv==f)return f;
        }
    }
    cur[x]=x[ls];
    if(!(--gp[d[x]])) d[S]=d[x]=pt;
    gp[++d[x]]++;
    return hv;
}
int main()
{
    freopen("D:/LiuYuanHao/a1.in","r",stdin);
    /*n=read(),m=read();
    S=n*m*3+1,T=n*m*3+2,pt=n*m*3+2;
    fo(i,1,n) fo(j,1,m)
    {
        int x=read();link(hh(i,j),T,x);ans+=x;
    }
    fo(i,1,n) fo(j,1,m)
    {
        int x=read();link(S,hh(i,j),x);ans+=x;
        if(i!=1) link(hh(i,j),hh(i-1,j)+n*m,oo),link(hh(i-1,j)+2*n*m,hh(i,j),oo);
        if(j!=1) link(hh(i,j),hh(i,j-1)+n*m,oo),link(hh(i,j-1)+2*n*m,hh(i,j),oo);
        if(i!=n) link(hh(i,j),hh(i+1,j)+n*m,oo),link(hh(i+1,j)+2*n*m,hh(i,j),oo);
        if(j!=m) link(hh(i,j),hh(i,j+1)+n*m,oo),link(hh(i,j+1)+2*n*m,hh(i,j),oo);
    }
    fo(i,1,n) fo(j,1,m)
    {
        int x=read();ans+=x;
        link(hh(i,j),n*m+hh(i,j),x);
        link(n*m+hh(i,j),T,x);
        link(S,n*m+hh(i,j),0);
    }
    fo(i,1,n) fo(j,1,m)
    {
        int x=read();ans+=x;
        link(2*n*m+hh(i,j),hh(i,j),x);
        link(2*n*m+hh(i,j),T,0);



        
        link(S,2*n*m+hh(i,j),x);
    }*/
    m=read(),pt=read();
    fo(i,1,m)
    {
        int x=read(),y=read(),v=read();
        link(x,y,v);
    }
    S=1,T=pt;
    gp[0]=pt;
    while(d[S]<pt) 
		ans+=nw(S,oo);
    printf("%d",ans);
}

#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=1010;
int S,T;
int d[N*N],dis[N],f[N][N],c[N][N],a[N][N];
int n,m,pt,ct[N][N],p[N][2],fr[N],ans;
bool bz[N];
bool spfa()
{
    int l=0,r=1;
    memset(dis,127,sizeof dis );
    memset(fr,0,sizeof fr);
    dis[1]=0,bz[1]=1;
    d[1]=1;
    while(l<r)
    {
        int k=d[++l];
        fo(i,1,a[k][0])
        {
            int p=a[k][i];
            if(f[k][p]&&dis[p]>dis[k]+c[k][p])
            {
                dis[p]=dis[k]+c[k][p],fr[p]=k;
                if(!bz[p]) bz[p]=1,d[++r]=p;
            }
        }
        bz[k]=0;
    }
    return (dis[T]!=oo);
}
void link(int x,int y,int v,int s)
{
    f[x][y]=v;
    c[x][y]=s,c[y][x]=-s;
    a[x][++a[x][0]]=y,a[y][++a[y][0]]=x;
}
void get()
{
    int k=T,v=oo;
    while(fr[k]) v=min(f[fr[k]][k],v),k=fr[k];
    k=T;
    while(fr[k]) ans+=v*c[fr[k]][k],f[fr[k]][k]-=v,f[k][fr[k]]+=v,k=fr[k];
    fo(i,1,m)
    {
        if(f[p[i][0]][T]==0)
        {
            p[i][0]=++pt,p[i][1]++;
            link(pt,T,1,0);
            fo(j,1,n) link(j+1,pt,1,ct[i][j]*p[i][1]);
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    pt=1;
    fo(i,1,n)
    {
    	int x;
        scanf("%d",&x);
        link(1,++pt,x,0);
    }
    fo(i,1,m) p[i][0]=(++pt),p[i][1]=1;
    T=(++pt);
    fo(i,1,m) link(p[i][0],pt,1,0);
    fo(i,1,n)
        fo(j,1,m)
        {
            scanf("%d",&ct[j][i]);
            link(i+1,p[j][0],1,ct[j][i]);
        }
    while(spfa()) get();
    printf("%d\n",ans);
}
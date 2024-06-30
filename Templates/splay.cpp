#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=100100;
int n,q;
int fa[N],son[N][2],a[N],mx[N],laz[N];
bool gl(int x){return(x==son[fa[x]][1]);}
void add(int x,int v){a[x]+=v,mx[x]+=v,laz[x]+=v;}
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
void down(int x)
{
    if (laz[x])
    {
        if(son[x][0])add(son[x][0],laz[x]);
        if(son[x][1])add(son[x][1],laz[x]);
        laz[x]=0;
    }
}
void updata(int x)
{
    mx[x]=a[x];
    fo(l,0,1)
    if(son[x][l])
    {
        down(son[x][l]);
        mx[x]=max(mx[x],son[x][l][mx]); 
    }
}
void rotate(int x)
{
    int y=fa[x],z=gl(x);
    down(y);down(x);
    son[y][z]=son[x][z^1];if(son[x][z^1])son[x][z^1][fa]=y;
    son[fa[x]=fa[y]][gl(y)]=x;
    son[fa[y]=x][z^1]=y;
    updata(y);
}
void splay(int x,int y)
{
    while (fa[x]!=y)
    {
        if (fa[fa[x]]!=y)
        {
            if (gl(x)==gl(fa[x]))rotate(fa[x]);
            else rotate(x);
        }
        rotate(x);
    }
    updata(x);
}
int build(int f,int l,int r)
{
    int m=l+r>>1;
    if (l<m)son[m][0]=build(m,l,m-1);
    if (m<r)son[m][1]=build(m,m+1,r);
    fa[m]=f;
    updata(m);
    return m;
}
int main()
{
//  freopen("D:/LiuYuanHao/a.in","r",stdin);
//  freopen("D:/LiuYuanHao/a.out","w",stdout);
    n=read();
    fo(i,2,n+1) a[i]=read();
    son[0][0]=build(0,1,n+2);/*新增两个点防止越界*/
    q=read();
    while(q--)
    {
        int t=read(),x=read()+1,y=read()+1;
        splay(x-1,0);splay(y+1,x-1);
        down(x-1);down(y+1);
        if(t==1)
        {
            t=read();
            add(son[y+1][0],t);
        }
        else printf("%d\n",son[y+1][0][mx]);
    }
}


#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=200200,mo=7459;
int n,a[N],m;
int fa[N],sn[N][2];
int su[N],sg[N];
char ch[10];
int gl(int x){return(sn[x[fa]][1]==x);}
int top,sz[N],rot;
int build(int f,int l,int r)
{
	if(l>r)return 0;
	int m=(l+r)>>1;
	sz[m]=1;
	fa[m]=f;
	if(l==r)
	{
		su[m]=a[m],sg[m]=1ll*a[m]*a[m]%mo;
		sz[fa[m]]+=sz[m];
		return m;	
	}
	sn[m][0]=build(m,l,m-1);
	sn[m][1]=build(m,m+1,r);
	su[m]=(sn[m][0][su]+sn[m][1][su]+a[m])%mo;
	sg[m]=(sn[m][0][sg]+sn[m][1][sg]+1ll*a[m]*a[m])%mo;
	sz[fa[m]]+=sz[m];
	return m;
}
int lz[N];
void down(int x)
{
	if(lz[x])
		fo(l,0,1)
		if(sn[x][l])
		{
			int y=sn[x][l];
			if(sz[y]>1)lz[y]=(lz[y]+lz[x])%mo;
			a[y]=(a[y]+lz[x])%mo;
			sg[y]=(sg[y]+1ll*lz[x]*lz[x]%mo*sz[y]%mo+2ll*su[y]*lz[x])%mo;
			su[y]=(su[y]+1ll*lz[x]*sz[y])%mo;
		}
	lz[x]=0;
}
void update(int x)
{
	down(x);
	sz[x]=1,su[x]=a[x],sg[x]=1ll*a[x]*a[x]%mo;
	fo(l,0,1) if(sn[x][l])
		su[x]=(su[x]+su[sn[x][l]])%mo,
		sg[x]=(sg[x]+sg[sn[x][l]])%mo,
		sz[x]=(sz[x]+sz[sn[x][l]]);
}
void rotate(int x)
{
	int p=gl(x),y=fa[x];
	down(y),down(x);
	sn[y][p]=sn[x][p^1];	
	if(sn[x][p^1]) sn[y][p][fa]=y;
	sn[fa[x]=fa[y]][gl(y)]=x;
	fa[sn[x][p^1]=y]=x;
	update(y);
	update(x);
}
void mkrt(int x,int rt)
{
	while(fa[x]!=rt)
	{
		if(x[fa][fa]!=rt)
		{
			if(gl(x)==gl(fa[x])) rotate(fa[x]);
			else rotate(x);
		}
		rotate(x);
	}
	update(x);
	if(rt==0) rot=x;
	else update(rt);
}
int kth(int rt,int x)
{
	while(sn[rt][0][sz]+1!=x) 
		if(sn[rt][0][sz]>=x) rt=sn[rt][0];
		else x-=sn[rt][0][sz]+1,rt=sn[rt][1];
	return rt;
}
void add(int x,int v)
{
	down(x);
	lz[x]=(lz[x]+v)%mo;
	a[x]=(a[x]+v)%mo;
	sg[x]=(sg[x]+1ll*v*v*sz[x]%mo+2ll*su[x]*v%mo)%mo;
	su[x]=(su[x]+1ll*v*sz[x])%mo;
	mkrt(x,0);
}
void insert(int p,int v)
{
	a[++top]=v;int tp;
	mkrt(kth(rot,p),0);mkrt(tp=kth(rot,p-1),rot);
	down(tp);
	fa[sn[tp][1]=top]=tp;
	su[top]=a[top],sg[top]=1ll*a[top]*a[top]%mo;
	sz[top]=1;
	mkrt(top,0);
}
void pplus(int l,int r,int v)
{
	int tp;
	mkrt(kth(rot,r+1),0);mkrt(tp=kth(rot,l-1),rot);	
	tp=sn[tp][1];
	add(tp,v);
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d",&n);
	fo(i,2,n+1) 
	{
		scanf("%d",&a[i]);
		a[i]=(a[i]%mo+mo)%mo;	
	}
	rot=build(0,1,n+2);top=n+2;
	sz[0]=0;
	scanf("%d",&m);
	int sj=0;
	while(m--)
	{
		scanf("%s ",ch+1);
		if(ch[1]=='I')
		{
			int x,y;
			scanf("%d%d",&x,&y);++x;y=(y%mo+mo)%mo;
			insert(x,y);
		}
		if(ch[1]=='A')
		{
			int x,y,c;
			scanf("%d%d%d",&x,&y,&c);++x,++y;
			c=(c%mo+mo)%mo;
			pplus(x,y,c);
		}
		if(ch[1]=='Q')
		{
			if(++sj==8)
				printf("");
			int x,y;
			scanf("%d%d",&x,&y);++x,++y;
			x=kth(rot,x-1); 
			y=kth(rot,y+1);			
			mkrt(x,0);mkrt(y,x);
			printf("%d\n",sn[y][0][sg]);
		}
	}
	return 0;
}












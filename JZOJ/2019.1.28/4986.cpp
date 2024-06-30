#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
int abs(int x){return(x<0)?(-x):x;}
const int N=200200;
int n,m;
int e[N],top;
int fa[N],sn[N][2],mx[N],mn[N],v[N];
int sz[N],rot; 
int gl(int x){return(sn[fa[x]][1]==x);}
int smn(int x,int y)
{
	if(x<y)swap(x,y);
	if(!y)return x;
	else return(y);
}
int nex[N],pre[N];
void update(int x)
{
	v[x]=oo,sz[x]=1;
	mx[x]=mn[x]=e[x];
	if(nex[x]!=x&&e[x])v[x]=min(v[x],abs(e[x]-nex[x][e]));
	fo(i,0,1)
	if(sn[x][i])
	{
		sz[x]+=sz[sn[x][i]];
		mx[x]=max(mx[x],sn[x][i][mx]),mn[x]=smn(mn[x],sn[x][i][mn]);
		v[x]=min(v[x],sn[x][i][v]);
	}
}
int build(int f,int l,int r)
{
	if(l>r)return 0;
	int m=(l+r)>>1;
	sz[m]=1;
	mx[m]=mn[m]=e[m];
	fa[m]=f;v[m]=oo;
	if(e[m])v[m]=min(v[m],abs(e[m]-nex[m][e]));
	if(l==r) return(m);
	sn[m][0]=build(m,l,m-1);
	sn[m][1]=build(m,m+1,r);
	update(m);
	return m;
}
void rotate(int x)
{
	int p=gl(x),y=fa[x];
	if(fa[y]) sn[fa[y]][gl(y)]=x;
	fa[x]=fa[y];fa[y]=x;
	sn[y][p]=sn[x][p^1];
	if(sn[x][p^1]) fa[sn[x][p^1]]=y;
	sn[x][p^1]=y;
	update(y);
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
int kth(int x,int rt)
{
	for(;;)
	{
		if(!sn[rt][0])
		{
			if(x==1)return rt;
			else --x,rt=sn[rt][1];
		}
		if(sn[rt][0][sz]+1==x) return rt;
		else if(sn[rt][0][sz]+1>x) rt=sn[rt][0];
		else x-=sn[rt][0][sz]+1,rt=sn[rt][1];
	}
}
char ch[11];
void insert(int x,int y)
{
	int tp;
	mkrt(tp=kth(x,rot),0),mkrt(x=kth(x+1,rot),tp);
	fa[sn[x][0]=++top]=x;e[top]=y;sz[top]=1;
	update(top);
	mkrt(top,0);
	nex[top]=x,pre[top]=tp;
	nex[top][pre]=top,pre[top][nex]=top;
}
void del(int x)
{
	int a=kth(x-1,rot),b=kth(x+1,rot);
	mkrt(b,0),mkrt(a,b);
	fa[sn[a][1]]=0,e[sn[a][1]]=0;sz[sn[a][1]]=0;
	int p=sn[a][1];sn[a][1]=0;
	if(nex[p])nex[p][pre]=pre[p];
	if(pre[p])pre[p][nex]=nex[p];
	nex[p]=pre[p]=0;
	update(a);
	mkrt(a,0);
}
int main()
{
//	freopen("D:/LiuYuanHao/a1.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	memset(v,127,sizeof v);
	scanf("%d%d",&n,&m);
	fo(i,2,n+1) 
	{
		scanf("%d",&e[i]);
		nex[i]=i+1,pre[i]=i-1;
	}
	nex[1]=2,pre[n+2]=n+1;
	rot=build(0,1,n+2);top=n+2;
	int sj=0;
	while(m--)
	{
		int x,y;
		scanf("%s %d %d",ch+1,&x,&y);++x;
		if(ch[2]=='a') 
		{
			++y;
			mkrt(x=kth(x-1,rot),0);
			mkrt(y=kth(y+1,rot),x);
			printf("%d\n",sn[y][0][mx]-sn[y][0][mn]);
		}
		if(ch[2]=='i')
		{
			++y;
			mkrt(x=kth(x-1,rot),0),mkrt(y=kth(y+1-1,rot),x);
			printf("%d\n",sn[y][0][v]);
		}
		if(ch[2]=='n')
		{
			insert(x,y);
		}
		if(ch[2]=='e')
		{
			del(x),del(x);
			insert(x-1,y);
		}
	}
	return 0;
}












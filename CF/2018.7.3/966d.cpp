#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),GGG=(y);i<=GGG;++i)
#define fd(i,x,y) for (int i=(x),GGG=(y);i>=GGG;--i)
using namespace std;
const int N=3003000;
int n,m;
int tn[N],sbz[N];
vector<int> to[N];
int read()
{
	int rt=0;char c=getchar();
	while(!(c>='0'&&c<='9'))c=getchar();
	while((c>='0'&&c<='9'))rt=rt*10+c-'0',c=getchar();
	return rt;
}
int ans[N];
int fa[N],dep[N],dfn[N],top[N],tot;
int bz[N],sta[N],cir[N];
vector<int> c[N];
int d[2*N],vis[N],p[N],t1[N];
void dfs(int x)
{
	if(bz[x])
	{
		if(sbz[x]&&t1[x])
		{
			int cnt=tot+1-dfn[x];
			c[dfn[x]].push_back(x);
			fd(i,sta[0],1) 
			{
				cir[sta[i]]=min(cir[sta[i]],cnt);
				if(x!=sta[i])
				{
					top[sta[i]]=top[x];
					c[dfn[x]].push_back(sta[i]);
				}
				else break;	
			}
		}
		return; 
	}
	sta[++sta[0]]=x;sbz[x]=bz[x]=1;
	top[x]=dfn[x]=++tot;
	fo(i,0,to[x].size()-1)
	if(to[x][i]!=fa[x]) 
	{
		to[x][i][fa]=x;
		dfs(to[x][i]);
	}
	sbz[sta[sta[0]--]]=0;
}
void solve(int x)
{
	int hd=0,tl=1;d[1]=1;vis[1]=1;
	dep[1]=1;
	while(hd++<tl)
	{
		int x=d[hd];
		fo(i,0,to[x].size()-1)
		if(!to[x][i][vis])
		{
			int tp=to[x][i];
			p[tp]=x;
			vis[tp]=1;
			dep[tp]=dep[x]+1;
			d[++tl]=tp;
			if(dep[tp]==3&&ans[0]>5)
			{
				ans[0]=5;
				ans[ans[0]]=n,ans[ans[0]-1]=1;
				ans[ans[0]-2]=tp;
				int tmp=tp,cmt=ans[0]-2;
				while(tmp!=1) ans[--cmt]=tmp=p[tmp];
			}/*
			if(cir[tp]<oo&&cir[tp]+dep[tp]<ans[0])
			{
				ans[0]=1+cir[tp]+dep[tp];
				int tmd=0,cmt=ans[0]-1;
				fo(l,0,c[top[tp]].size()-1)
				if(c[top[tp]][l]==tp) 
				{
					tmd=l;
					break;
				}
				ans[ans[0]]=n;ans[ans[0]-1]=tp;
				fd(l,tmd-1,0) ans[--cmt]=c[top[tp]][l];
				fd(l,c[top[tp]].size()-1,tmd) ans[--cmt]=c[top[tp]][l];
				int tmp=tp;
				while(tmp!=1) ans[--cmt]=tmp=p[tmp];
			}*/
			if(tn[tp]&&dep[tp]+1<ans[0])
			{
				ans[0]=dep[tp]+1;
				ans[ans[0]]=n,ans[ans[0]-1]=tp;
				int tmp=tp,cmt=ans[0]-1;
				while(tmp!=1) ans[--cmt]=tmp=p[tmp];
			}
		}
	}
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	memset(cir,127,sizeof cir);
	n=read(),m=read();
	ans[0]=oo;
	fo(i,1,m)
	{
		int x=read(),y=read();
		if(x==n)tn[y]=1;if(y==n)tn[x]=1;
		if(x==1)t1[y]=1;if(y==1)t1[x]=1;
		to[x].push_back(y),to[y].push_back(x);
	}
	if(tn[1])
	{
		printf("1\n1 %d",n);
		return 0;
	}
	dfs(1);
	solve(1);
	if(ans[0]==oo)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",ans[0]-1);
	fo(i,1,ans[0])
		printf("%d ",ans[i]);
	return 0;
}












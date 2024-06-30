#pragma GCC optimize(2) 
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),G=(y);i<=G;++i)
using namespace std;
const int N=2*200200;
int n,fa[N],du[N];
int root,ans[N],bz[N];
int las[N];
struct edge{
	int nex,pre,to;
}t[N];
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
void des(int x)
{
	ans[++ans[0]]=x;
	--fa[x][du];
	for (int tp=las[x];tp;tp=t[tp].pre)
	{
		int tt=t[tp].to;
		--du[tt];
	}
}
void del(int x)
{
	t[x].to=0;
	t[t[x].pre].nex=t[x].nex;
	t[t[x].nex].pre=t[x].pre;
}
void dfs(int x)
{
	for (int tp=las[x];tp;tp=t[tp].pre)
	{
		int tt=t[tp].to;
		dfs(tt);
		if(bz[tt]) 
		{
			if(tp==las[x]) las[x]=t[tp].pre;
			del(tp);
		}
	}
	if((du[x]&1)==0&&!bz[x])
	{
		bz[x]=1,des(x);
		for (int tp=las[x];tp;tp=t[tp].pre)
		{
			int tt=t[tp].to;
			dfs(tt);
			if(bz[tt]) 
			{
				if(tp==las[x]) las[x]=t[tp].pre;
				del(tp);
			}
		}
	}
}
int tot=0;
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	n=read();
	fo(i,1,n) 
	{
		fa[i]=read();
		if(!fa[i]) root=i;
		else 
		{
			t[++tot].to=i,t[tot].pre=las[fa[i]],las[fa[i]]=tot,t[t[tot].pre].nex=tot;
			++du[i],++du[fa[i]];
		}
	}
	if(!(n&1))
	{
		printf("NO\n");
		return 0;
	}
	dfs(root);
	printf("YES\n");
	fo(i,1,n)
		printf("%d\n",ans[i]);
	return 0;
}


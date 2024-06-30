#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (ll i=(x);i<=(y);++i)
using namespace std;
const ll N=10010,M=2*20020;
ll read()
{
	ll rt=0,tp=1;
	char ch=getchar();
	while(!((ch>='0'&&ch<='9') || (ch=='-'))) ch=getchar();
	if(ch=='-') tp=-1,ch=getchar();
	while(ch>='0'&&ch<='9') rt=rt*10+ch-'0',ch=getchar();
	return rt*tp;
}
ll T,n,m,tot=0;
ll to[M],nex[M],las[N];
ll c[N];
ll flag;
void link(ll x,ll y)
{
	to[++tot]=y,tot[nex]=las[x];las[x]=tot;
}
void dfs(ll x,ll cl)
{
	if(flag) return;
	for (ll tp=las[x];tp;tp=tp[nex])
	if(tp[to][c]<0)
	{
		tp[to][c]=(cl^1);	
		dfs(tp[to],cl^1);
	}
	else
	if(tp[to][c]==cl) 
	{
		flag=1;
		return;
	}
}
ll main()
{
	 freopen("color.in","r",stdin);
	 freopen("color.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	T=read();
	while(T--)
	{
		flag=0;
		memset(las,0,sizeof las);
		tot=0;memset(c,255,sizeof c);
		n=read(),m=read();
		fo(i,1,m)
		{
			ll x=read(),y=read();
			link(x,y),link(y,x);
		}
		c[1]=0;
		dfs(1,0);
		if(!flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}












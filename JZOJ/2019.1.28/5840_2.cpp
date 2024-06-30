#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=2*100100;
int n,m;
int du[N];
int ans[N*2][2];
int las[N],nex[N],to[N],bz[N];
int tot;
void link(int x,int y)
{
	nex[++tot]=las[x],to[tot]=y,las[x]=tot;
	bz[tot]=0;
}
int a0=0,endi;
void go(int x)
{
	if(endi) return;
	int flag=1,mx=0,mxx=0;
	for(int tp=las[x];tp;tp=tp[nex])
	if(!tp[bz]&&(to[tp][du]&1)==0)
	{
		flag=0;
		if(du[to[tp]]>mx) mx=du[to[tp]],mxx=tp;
	}
	if(flag) 
	{	
		for(int tp=las[x];tp;tp=tp[nex])
		if(!bz[tp])
		{
			flag=0;
			bz[tp]=bz[tp^1]=1;
			--du[x],--du[to[tp]];
			ans[++a0][0]=0,ans[a0][1]=to[tp];
			endi=1;
			return;	
		}	
	}
	else 	
	{
		int tp=mxx;
		bz[tp]=bz[tp^1]=1;
		--du[x],--du[to[tp]];
		ans[++a0][0]=0,ans[a0][1]=to[tp];
		go(to[tp]);
		return;
	}
	if(flag) return;
}
int main()
{
	freopen("D:/LiuYuanHao/b.in","r",stdin);
	freopen("D:/LiuYuanHao/b.out","w",stdout);
	scanf("%d%d",&n,&m);
	tot=1;
	fo(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
		++du[x],++du[y];
	}
	int cnt=0;
	fo(i,1,n) 
		if(du[i]&1) 
		{
			endi=0;
			++cnt;
			ans[++a0][0]=1,ans[a0][1]=i;
			go(i);
		}
	fo(i,1,n) 
		if(du[i]>0) 
		{
			++cnt;
			ans[++a0][0]=1,ans[a0][1]=i;
			go(i);
		}
	printf("%d\n%d\n",cnt-1,ans[1][1]);
	fo(i,2,a0)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}












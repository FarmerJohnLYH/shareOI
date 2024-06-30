#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i) 
using namespace std; 
const int N=200200;
int n,to[N*2],nex[N*2],las[N],tot;
int c[N*2],v[N],ans;
void link(int x,int y,int d)
{
    to[++tot]=y,nex[tot]=las[x],las[x]=tot;
	c[tot]=d;
}
void dfs(int x,int f)
{
	int cnt=0;
	v[x]=0;
	for(int tp=las[x];tp;tp=tp[nex])
	if(to[tp]!=f)
	{
		++cnt;
		dfs(to[tp],x);	
		v[x]+=c[tp];
		if(c[tp]!=to[tp][v] && to[tp][v]!=0) 
			++ans;
	}
	if(cnt-abs(v[x]))
		ans+=(cnt-abs(v[x]))/2;
	if(abs(v[x])>1)
		ans+=abs(v[x])-1,v[x]=v[x]/abs(v[x]);
}
int main() 
{
	freopen("D:/LiuYuanHao/b1.in","r",stdin);
//	freopen("b.out","w",stdout);
	scanf("%d",&n);
	fo(i,1,n-1)
	{
		int x,y;scanf("%d%d",&x,&y);
		++x,++y;
		link(x,y,1),link(y,x,-1);
	}
	dfs(1,0);	
	ans+=abs(v[1]);
	printf("%d\n",ans);	
}








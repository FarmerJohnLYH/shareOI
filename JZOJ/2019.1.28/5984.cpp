#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=500500,mo=1000109107;
int n,m;
int to[N*2],nex[N*2],las[N];
int fa[N],a[N],tot,va[N],w[N];
void link(int x,int y)
{
	to[++tot]=y,nex[tot]=las[x],las[x]=tot;
}
ll sum,ans;
void work(int x)
{
	for(int tp=las[x];tp;tp=tp[nex])
	{
		++w[to[tp]];
		sum^=w[to[tp]];
	}
}
int main()
{
	freopen("cactus.in","r",stdin);
	freopen("cactus.out","w",stdout);
	// freopen("D:/LiuYuanHao/b.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y),link(y,x);
	}
	fo(i,1,m) 
	{
		scanf("%d",&a[i]),va[i]=1ll*i*(i+1)%mo;
		sum=0;
		work(a[i]);
		ans=(ans+sum*va[i])%mo;
	}
	printf("%lld\n",ans);
	return 0;
}








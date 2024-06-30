#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
typedef long long ll;
using namespace std;
const int N=2020,eps=1010;
int md[N][N],las[N],nex[N],id[N];
ll sum[N][N],a[N];
int tot;
int n,q,l,r;
ll abs(ll x)
{
	return((x)<0)?(-x):((x));
}
int main()
{	
//	freopen("D:/LiuYuanHao/b.in","r",stdin);
     
	scanf("%d%d",&n,&q);
	fo(i,1,n) scanf("%d",&a[i]);
	fo(i,1,n)
	{
		memset(las,0,sizeof las);
		tot=0;
		l=0,r=0;
		fd(j,i,1)
		{
			if(a[j]>a[i])r++;else l++;
			id[++tot]=j,nex[tot]=las[r-l+eps],las[r-l+eps]=tot;
		}
		l=-1,r=0;
		fo(j,i,n)
		{
			if(a[j]>a[i])r++;else l++;
			for(int tp=las[l-r+eps];tp;tp=nex[tp])
				if(((j-id[tp]+1)&1)==0)	md[id[tp]][j]=i;
			for(int tp=las[l-r-1+eps];tp;tp=nex[tp])	
				if(((j-id[tp])&1)==0) md[id[tp]][j]=i;
		}
	}
	fo(i,1,n) fo(j,1,n)
		sum[i][j]=sum[i][j-1]+1ll*abs(a[j]-a[i]);
	ll ans=0;
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ans+=sum[md[x][y]][y]-sum[md[x][y]][x-1];
	}
	printf("%lld\n",ans);
	return 0;
}

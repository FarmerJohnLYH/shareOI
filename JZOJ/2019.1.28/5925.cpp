#include <cstdio>
#include <cstring>
#include <iostream>
#define inf (1ll<<62)
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=330,C=100100;
int n,T;
ll a[N],f[N];
ll mn[N][N],va[N][N];
int bz[C];
ll c[N],c0;
int main()
{
	 freopen("colour.in","r",stdin);
	 freopen("colour.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		memset(mn,127,sizeof mn),memset(va,0,sizeof va);
		memset(bz,0,sizeof bz);
		c0=0;
		scanf("%d",&n);
		fo(i,1,n)
		{ 
			scanf("%lld",&a[i]);
			if(!bz[a[i]]) c[++c0]=a[i];
			bz[a[i]]=1;
		}
			fo(i,1,n) 
			{
				mn[i][i]=a[i];
				fo(j,i+1,n)mn[i][j]=min(mn[i][j-1],a[j]);
			}
		fo(scc,1,c0)
		{
			ll sc=c[scc];
			fo(i,1,n) 
			{
				ll sum=0;
				if(sc!=a[i]) sum=a[i]*sc;
				if(mn[i][i]==sc) va[i][i]=sum; 
				fo(j,i+1,n)
				{
					if(sc!=a[j]) sum+=a[j]*sc;
					if(mn[i][j]==sc) va[i][j]=sum; 
				}
			}
		}
		ll ans=inf;
		fo(scc,1,c0)
		{
			ll sc=c[scc];
			memset(f,127,sizeof f);
			f[0]=0;
			fo(i,0,n-1)
			if(f[i]<inf)
			{
				fo(j,1,n-i)
				{
					int l=i+1,r=i+j;
					f[r]=min(f[r],f[i]+va[l][r]+((mn[l][r]==sc)?0:(sc*mn[l][r]*j)));
				}
			}
			ans=min(ans,f[n]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}









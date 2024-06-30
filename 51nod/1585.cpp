#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=500500,M=10001000,mo=1e9+7;
int n,a[N];
int p[417316],bz[M],p0;
int cnt[M],miu[M];
ll tw[M];
int pre[M],mx;
ll ans;
void init()
{
	bz[1]=1;miu[1]=1,pre[1]=1;
	fo(i,2,M-100)
	{
		if(!bz[i]) p[++p0]=i,miu[i]=-1,pre[i]=i;
		fo(j,1,p0)
		{
			if(1ll*p[j]*i>M-10)break;
			bz[p[j]*i]=1,pre[p[j]*i]=p[j];
			if(i%p[j]==0)break;
			else miu[i*p[j]]=-miu[i];
		}
	}
	int cc=0;
	tw[0]=1;fo(i,1,M-100)tw[i]=tw[i-1]*2%mo;
}
void add(ll &x,ll y)
{
	x=(x+y)%mo;
}
int max(int x,int y)
{
	return(x>y)?x:y;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d",&n);
	fo(i,1,n)
	{
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
		++cnt[a[i]];
	}
	init();
	fo(v,2,mx)
	if(miu[v]!=0)
	{
		int ct=0;
		fo(j,1,mx/v)
			ct+=cnt[(j*v)];
		add(ans,-1ll*miu[v]*(tw[ct]-1)%mo*(n-ct)%mo);
	}
	printf("%lld\n",(ans+mo)%mo);
	return 0;
}









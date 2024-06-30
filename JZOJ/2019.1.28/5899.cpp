#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const ll N=330,M=2020,mo=998244353;
int n,m,p;
ll qsm(ll x,ll y)
{
	ll rt=1;
	fo(i,0,30)
	{
		if((1<<i)&y) rt=rt*x%mo;
		x=x*x%mo;
	}
	return rt;
}
struct mtx{
	ll det,a[N][N];
	void solve()
	{
		fo(i,1,p) fo(j,1,p) a[i][j]=(a[i][j]%mo+mo)%mo;
		fo(i,1,p-1)
			fo(j,i+1,p)
			{
				ll tp=a[j][i]*qsm(a[i][i],mo-2)%mo;		
				fo(k,1,p) a[j][k]=((a[j][k]-a[i][k]*tp)%mo+mo)%mo;
 			}
 		det=1;
		fo(i,1,p) det=det*a[i][i]%mo; 
	}
}a,b;
ll ans,cnt;
int main()
{
	 freopen("avg.in","r",stdin);
	 freopen("avg.out","w",stdout);
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
	scanf("%d%d",&n,&m);
	p=n-1;
	fo(i,1,m)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		a.a[x][y]=a.a[y][x]=-c;
		b.a[x][y]=b.a[y][x]=-1;
		a.a[x][x]+=c;a.a[y][y]+=c;
		b.a[x][x]++,b.a[y][y]++;
	}
	b.solve();
	a.solve();
	ans=a.det*qsm(b.det,mo-2)%mo;
	ans=(ans+mo)%mo;
	printf("%lld\n",ans);
	return 0;
}









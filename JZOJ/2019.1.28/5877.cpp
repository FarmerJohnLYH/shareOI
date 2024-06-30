#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=50050*2;
int f[N],n,m,k;
int cn;
struct xy{
	int x,y,id;
}a[N],P,Q;
bool cmp(xy a,xy b)
{
	return(a.x+a.y<b.x+b.y);
}
int mul(xy a,int x,int y)
{
	ll rt;
	rt=1ll*a.x*y-1ll*a.y*x;
	if(rt>0) return 1;
	if(rt<0) return -1;
	return 0;
}
int check(int x,int y)
{
	return(mul(P,x,y)*mul(Q,x,y)<=0);
}
void dp(int en)
{
	fo(i,1,en) f[i]=1;
	fo(i,1,en-1)
	{
		fo(j,i+1,en)
		if(check(a[j].x-a[i].x,a[j].y-a[i].y))
			f[j]=max(f[j],f[i]+1);
	}
}
int te[N];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	freopen("D:/LiuYuanHao/c.in","r",stdin);
	scanf("%d%d",&n,&k);
	scanf("%d%d%d%d",&P.x,&P.y,&Q.x,&Q.y);
	swap(P,Q);
	cn=n;
	fo(i,1,n)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id=i;
	}
	scanf("%d",&m);
	while(m--)
	{
		int opt;scanf("%d",&opt);
		if(opt==1)
		{
			int x;scanf("%d",&x);
			sort(a+1,a+1+n,cmp);fo(i,1,n) te[a[i].id]=i;
			dp(te[x]);
			printf("%d\n",f[te[x]]);
		}
		else 
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[++n].x=x,a[n].y=y;
			a[n].id=n;
		}
	}
	return 0;
}









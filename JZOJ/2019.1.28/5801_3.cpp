#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fi first
#define se second 
using namespace std;
typedef pair<int,int> PI;
const int N=100100;
int f[N],n,m;
PI a[N],c[N];int d[N];
int cnt;
bool cmp(PI a,PI b)
{
	return(a.fi<b.fi||(a.fi==b.fi&&a.se<b.se));
}
int bz[N];
int main()
{
	// freopen("circular.in","r",stdin);
	// freopen("circular.out","w",stdout);
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&m,&n);
	fo(i,1,n)
	{
		scanf("%d%d",&a[i].fi,&a[i].se),--a[i].se;	
		
	}
	sort(a+1,a+1+n,cmp);
	int ans=0;
	fo(i,1,n)
	if(!bz[i])
	{
		int st=a[i].fi,en=a[i].se;
		if(en<st)en+=m;
		fo(j,1,n)
		{
			c[j]=a[j];
			if(c[j].fi<st) c[j].fi+=m;
			if(c[j].se<st) c[j].se+=m;
		}
		int tp=1;
		fo(j,i+1,n)
		if(a[j].fi>en&&a[j].se<st+m)
		{
			en=a[j].se,++tp;
			bz[j]=1;
		}	
		fo(j,1,i-1)
		{
			if(a[j].fi>en&&a[j].se<st+m)
			{
				en=a[j].se,++tp;
				bz[j]=1;
			}
		}
		ans=max(ans,tp);
	}
	printf("%d\n",ans);
	return 0;
}












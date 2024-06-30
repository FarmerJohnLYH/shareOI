#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define mi(x) (1ll<<(x))
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef long double db;
typedef long long ll;
const int N=30030*2;
const ll eps=1e9;
int n,l;
struct node{
	ll a,b,c;
	db v;
}a[N];
db f[N];
ll st[18][N];
int d[N],d0,lg[N];
void unq()
{
	fo(i,1,n) d[++d0]=a[i].c;
	sort(d+1,d+1+d0);
	fo(i,1,n) a[i].c=upper_bound(d+1,d+1+d0,a[i].c)-d;
	fo(i,1,n) d[a[i].c]=a[i].c;
	fd(i,n,1) a[i].c=d[a[i].c]--,st[0][i]=i;
}
ll fmx(int le,int ri)
{
	int p=lg[ri-le+1]-1;
	if(a[st[p][le]].c>a[st[p][ri-mi(p)+1]].c) return(st[p][le]);
	else return(st[p][ri-mi(p)+1]);
}
int check(ll p)
{
	fo(i,1,n) a[i].v=(db)a[i].a*eps-(db)a[i].b*p,f[i]=-(db)oo*oo;
	f[0]=0;
	fo(i,1,n)
	{
		fo(j,max(i-l,0),i-1)
			f[i]=max(f[i],f[j]+a[fmx(j+1,i)].v);
	} 
	return(f[n]>-1e-9);
}
int main()
{
	 freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&n,&l);
	fo(i,1,n) lg[i]=lg[i>>1]+1;
	fo(i,1,n)
		scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
	unq();	
	fo(j,1,16) fo(i,1,n)
	{
		if(i+mi(j-1)<=n)
			st[j][i]=(a[st[j-1][i]].c>a[st[j-1][i+mi(j-1)]].c)?st[j-1][i]:st[j-1][i+mi(j-1)];
		else st[j][i]=(a[st[j-1][i]].c>a[st[j][i-1]].c)?st[j-1][i]:st[j][i-1];
	}
	ll le=0,ri=2e16,ans=0;
	while(le<=ri)
	{ 
		ll mid=(le+ri)>>1;
		if(check(mid)) ans=mid,le=mid+1;
		else ri=mid-1;
	}
	int cnt=0;
	if(ans==0)printf("0.000000000e+000\n");
	else
	{
		while(ans<eps) ans*=10,--cnt;
		while(ans>=eps*10) 
		{
			if(ans<=eps*100) ans=((ans+5));
			ans/=10,++cnt;
		}
		printf("%lld.%llde",ans/eps,ans%eps);
		if(cnt<0)cnt=-cnt,putchar('-');else putchar('+');
		if(cnt<100)printf("0");if(cnt<10)printf("0");if(cnt<1)printf("0");
		printf("%d\n",cnt);
	}
	return 0;
}












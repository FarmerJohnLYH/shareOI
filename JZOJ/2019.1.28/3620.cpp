#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x),asdfgh=(y);i<=asdfgh;++i)
#define fd(i,x,y) for (int i=(x);asdfgh=(y);i>=asdfgh;--i)
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef pair<int,int> PI;
int abs(int x) {return(((x)>=0)?(x):(-(x)));}
int max(int x,int y) {return(((x)>(y))?(x):(y));}
int min(int x,int y) {return(((x)<(y))?(x):(y));}
int lowbit(int x) {return((x)&(-x));}
const int N=100100,mo=30013;
struct node{
	int a,b,c,d;
	int x,y;
	//lu ru ld rd
}a[N];
bool cmp(node a,node b)
{
	return a.c<b.c;
}
int n;
PI f[N],ans;
PI max(PI a,PI b)
{
	PI rt;
	if(a.fi==b.fi) rt.fi=a.fi,rt.se=(a.se+b.se)%mo;
	else
	{
		if(a.fi>b.fi) return a;else return b;
	}
	return rt;
}
int d[N],hd,tl;
PI tr[N*2];
void insert(PI x,int p)
{
	while(p<=2*n)
	{
		tr[p]=max(tr[p],x);
		p+=lowbit(p);
	}
}
PI nul;
PI query(int p)
{
	PI rt=nul;
	while(p)
	{
		rt=max(rt,tr[p]);
		p-=lowbit(p);
	}
	++rt.fi;
	return rt;
}
PI buf[N*2];
void lsh()
{
	fo(i,1,n)
	{
		buf[i].fi=a[i].x,buf[i].se=i;
		buf[i+n].fi=a[i].y,buf[i+n].se=i+n;
	}
	sort(buf+1,buf+1+2*n);
	fo(i,1,2*n)
	{
		if(buf[i].se<=n) a[buf[i].se].a=i;
		else a[buf[i].se-n].b=i;
	}
}
priority_queue<PI> q;
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("trapezoid.in","r",stdin);
//	freopen("trapezoid.out","w",stdout);
	scanf("%d",&n);
	nul.fi=-1,nul.se=0;
	fo(i,1,n) 
		scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].c,&a[i].d);
	sort(a+1,a+1+n,cmp);
	lsh();
	f[1].fi=f[1].se=1;
	ans.fi=1,ans.se=1;
	q.push(make_pair(-a[1].d,1));
	fo(i,2,n)
	{
		f[i].fi=1,f[i].se=1;
		PI tmp=q.top();
		while(!q.empty()&&(-tmp.fi<=a[i].c))
		{ 
			q.pop();
			insert(f[tmp.se],a[tmp.se].b);
			tmp=q.top();
		}
		f[i]=max(f[i],query(a[i].a));
		q.push(make_pair(-a[i].d,i));
		ans=max(f[i],ans);
//		printf("%d %d\n",f[i].fi,f[i].se);
	}
	printf("%d %d\n",ans.fi,ans.se);
	return 0;
}



#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fi first
#define se second 
using namespace std;
const int N=200200*2,T=50500;
typedef double db;
typedef pair<db,db> PI;
int n,m;
char str[10];
PI li[N];
int to[N*4];
db get(int x,db d)
{
	return(li[x].fi*d+li[x].se);
}
void ch(int x,int l,int r,int n)
{
	if(!to[x])
	{
		to[x]=n;
		return;
	}
	if(l==r)
	{
		if(get(to[x],l)<get(n,l)) to[x]=n;
		return;
	}
	int mid=(l+r)>>1;
	if((get(to[x],l)>get(n,l)&&get(to[x],r)>get(n,r)))return;
	if((get(to[x],l)<=get(n,l)&&get(to[x],r)<=get(n,r))) to[x]=n;
	else 
	{
		db xp=(db)(to[x][li].se-n[li].se)/(db)(to[x][li].fi-n[li].fi);
		if(get(to[x],l)>get(n,l)) 
		{
			if(xp<=mid)ch(x<<1,l,mid,n);
			else ch(x<<1|1,mid+1,r,to[x]),to[x]=n;
		}
		else
		{
			if(xp>mid)ch(x<<1|1,mid+1,r,n);
			else ch(x<<1,l,mid,to[x]),to[x]=n;
		}
	}
}
db qry(int x,int l,int r,int d)
{
	if(!to[x])return 0.00;
	if(l==r) return(get(to[x],d));
	int mid=(l+r)>>1;
	db rt=get(to[x],d);
	if(d<=mid) rt=max(rt,qry(x<<1,l,mid,d));
	else rt=max(rt,qry(x<<1|1,mid+1,r,d));
	return rt;
}
int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	int _;scanf("%d",&_);
	while(_--)
	{
		scanf("%s",str);
		if(str[0]=='P')
		{
			++n;
			scanf("%lf%lf",&li[n].se,&li[n].fi);
			li[n].se-=li[n].fi;
			ch(1,1,T,n);
			printf("");
		}
		else
		{
			int x;
			scanf("%d",&x);
			db q=qry(1,1,T,x);
//			printf("%lf\n",q);
			printf("%lld\n",(long long)floor(q/(db)100.0));
		}
	}
	return 0;
}












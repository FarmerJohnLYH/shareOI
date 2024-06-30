#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define fi first
#define se second 
using namespace std;
typedef pair<int,int> PI;
const int N=100100*4*4,eps=2;
int n,m;
PI a[N],v[N*4];
int f[22][N],bz[N];
int tot=1,t[N*4][2];
bool cmp(PI a,PI b)
{
//	return (a.fi<b.fi)||;
//	return(a.fi==b.fi)?(a.se<b.se):(a.fi<b.fi);
	return(a.se==b.se)?(a.fi<b.fi):(a.se<b.se);
}
void add(int x,int l,int r,int p,int va,int wz)
{
	if(l==r) 
	{
		if(v[x].fi>=va) 
			v[x]=make_pair(va,wz);
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)
	{
		if(!t[x][0])t[x][0]=++tot,v[tot]=make_pair(oo,0);
		add(t[x][0],l,mid,p,va,wz);
	}
	else
	{
		if(!t[x][1])t[x][1]=++tot,v[tot]=make_pair(oo,0);
		add(t[x][1],mid+1,r,p,va,wz);
	}
	fo(l,0,1) 
		if(t[x][l]&&v[t[x][l]].fi<=v[x].fi) v[x]=v[t[x][l]];
}
PI query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return(v[x]);
	int mid=(l+r)>>1;PI tp,rt=make_pair(oo,0);
	if(ql<=mid&&t[x][0]) 
	{
		tp=query(t[x][0],l,mid,ql,qr);
		if(tp.fi<=rt.fi) rt=tp;
	}
	if(qr>mid&&t[x][1])
	{
		tp=query(t[x][1],mid+1,r,ql,qr);
		if(tp.fi<=rt.fi) rt=tp;	
	}
	return rt;
}
int main()
{
	 freopen("circular.in","r",stdin);
	 freopen("circular.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%d%d",&m,&n);
	fo(i,1,n)
	{
		scanf("%d%d",&a[i].fi,&a[i].se);
		++a[i].fi,++a[i].se;
		if(a[i].fi>a[i].se) a[i].se+=m;
		fo(l,1,eps-1) 
		{
			a[i+l*n]=a[i+(l-1)*n];
			a[i+l*n].fi+=m,a[i+l*n].se+=m;
		}
	}
	m*=(eps),n*=(eps);v[1]=make_pair(oo,0);
	sort(a+1,a+1+n,cmp);
	fd(i,n,1)
	{
		PI q=query(1,1,m,a[i].se,m);
		f[0][i]=q.se;
 		add(1,1,m,a[i].fi,a[i].se,i);
	}
	fo(l,1,20) fo(i,1,n) f[l][i]=f[l-1][f[l-1][i]];
	int ans=0;
	fo(i,1,n)
	{
		int x=i,cnt=1;
		fd(l,20,0)
			if(f[l][x]&&f[l][x][a].se-a[i].fi<=(m/(eps))) 
			{
				x=f[l][x];
				cnt+=(1<<l); 
			}
		ans=max(ans,cnt);
	}
	printf("%d\n",min(n/eps,ans));
	return 0;
}












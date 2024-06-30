#pragma GCC optimize(2) 
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
typedef double db;
const int N=50050,NM=1001000;
int n,m,k[N],len;
int a[N],c[NM],la[N];
struct node{
	int l,r,x,id;
}q[N];int q0,p0;
struct cg{
	int x,v,pre;
}p[N];
int ans;
bool cmp(node a,node b) 
{
	if(k[a.l]!=k[b.l])return(k[a.l]<k[b.l]);
	if(k[a.r]!=k[b.r])return(k[a.r]<k[b.r]);
	return(a.x<b.x);
}
void change(cg a,int flag)
{
	if(flag==-1) swap(a.v,a.pre);
	if(!(--c[a.pre])) --ans;
	if((++c[a.v])==1) ++ans;
}
void add(int x,int y)
{
	if(y==-1) 
	{
		if((--c[x])==0) --ans;
	}
	else
		if((++c[x])==1) ++ans;
}
int cnt[N];
int main()
{
	freopen("len.in","r",stdin);
	freopen("len.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d",&n,&m);
	len=(db)pow((db)n,(db)0.667);
	fo(i,1,n) scanf("%d",&a[i]),la[i]=a[i],k[i]=(i/len)+1,++c[a[i]];
	scanf("\n");
	fo(i,1,m)
	{
		char g=getchar();int x,y;
		while(g!='M'&&g!='Q')g=getchar();
		scanf("%d %d\n",&x,&y);++x;
		if(g=='Q') q[++q0].l=x,q[q0].r=y,q[q0].x=p0,q[q0].id=q0;
		else p[++p0].x=x,p[p0].v=y,p[p0].pre=la[x],la[x]=y;
	}
	sort(q+1,q+1+q0,cmp);
	int lp=1,rp=n,cp=0;
	fo(i,0,100000)
	if(c[i]) ++ans;
	fo(i,1,q0)
	{
		int l=q[i].l,r=q[i].r,cu=q[i].x;
		if(cp<cu)fo(j,cp+1,cu) 
		{
			if(p[j].x>=lp&&p[j].x<=rp)change(p[j],1);
			a[p[j].x]=p[j].v;
		}
		else fd(j,cp,cu+1) 
		{
			if(p[j].x>=lp&&p[j].x<=rp)change(p[j],-1);
			a[p[j].x]=p[j].pre;
		}
		if(lp<l) fo(j,lp,l-1) add(a[j],-1);
		else fd(j,lp-1,l) add(a[j],1);
		if(rp<r) fo(j,rp+1,r) add(a[j],1);
		else fd(j,rp,r+1) add(a[j],-1);
		cnt[q[i].id]=ans;
		lp=l,rp=r,cp=cu;
	}
	fo(i,1,q0) printf("%d\n",cnt[i]);
	return 0;
}









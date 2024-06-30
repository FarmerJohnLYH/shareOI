#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=100100*2;
int n;
int w[N],f[N];
char s[N];
struct tr{
	int t[N];
	int lowbit(int x){return(x&(-x));}
	int qry(int x)
	{
		int rt=0;
		for(;x;x-=lowbit(x)) rt+=t[x];
		return rt;
	}
	int add(int x,int v)
	{
		for(;x<=n;x+=lowbit(x))t[x]+=v;
	}

}t;
void manacher()
{
	int l=1;f[1]=1;
	fo(i,2,n)
	{
		if(l+f[l]>=i)f[i]=min(i-l-f[l],f[l-(i-l)]);
		while(s[i+f[i]+1]==s[i-f[i]-1]&&i-f[i]-1>=1&&i+f[i]+1<=n)++f[i];
		if(i+f[i]>l+f[l]) l=i;
	}
}
struct node{
	int l,r,id,ans,;
}q[N];int q0;
bool cml(node a,node b)
{
	return(a.l==b.l)?(a.r<b.r):(a.l<b.l);
}
bool cmi(node a,node b)
{
	return a.id<b.id;
}
void solve(int flag)
{
	
}
int main()
{
	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%s",s+1);n=strlen(s+1);
	fd(i,n,1) s[i*2]=s[i],s[i*2+1]='&';s[1]='&';
	n=n*2+1;
	manacher();
	scanf("%d",&q0);
	fo(i,1,q0)
	{
		scanf("%d%d",&q[i].l,&q[i].r);q[i].id=i;
		q[i].ans=0;q[i].m=(q[i].l+q[i].r)>>1;
	}
	sort(q+1,q+1+q0,cml);
	solve(0);
	solve(1);
	sort(q+1,q+1+q0,cmi);
	fo(i,1,q0)
		printf("%d\n",q[i].ans);
	return 0;
}














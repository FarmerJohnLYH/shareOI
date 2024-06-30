//考虑用SA 然后在SA上区间加减 如果使用线段树会多一个Log 
//总之 GG
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
const int N=1001000,M=27,mo=1000000007;
int sa[N],rank[N],tp[N];
int tax[M];
int n,m;
char st[N];
void Rsort()
{
	fo(i,0,m) tax[i]=0;
	fo(i,1,n) ++tax[rank[tp[i]]];
	fo(i,1,m) tax[i]+=tax[i-1];
	fd(i,n,1) sa[tax[rank[tp[i]]]--]=tp[i];
}
int cmp(int *f,int x,int y,int v)
{
	return(f[x]==f[y]&&f[x+v]==f[y+v]);
}
void SA()
{
	fo(i,1,n) rank[i]=st[i],tp[i]=i;
	m=M;
	Rsort();
	int w=1;
	while((w*=2)<=n)
	{
		int p=0;
		fo(i,n-w+1,n) tp[++p]=i; 
		fo(i,1,n) 
		if(sa[i]>w) tp[++p]=sa[i]-w;

		Rsort();swap(rank,tp);rank[sa[1]]=(p=1);
		fo(i,2,n)
			rank[i]=(cmp(tp,i,i-1,w))?p:(++p);
		m=p;
	}
}
int main()
{
	freopen("D:/LiuYuanHao/","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",st+1);
		n=strlen(st+1);
		fo(i,1,n) st[i]-='a';
		SA();
		int lal=1,lar=n,l=1,r=n;
		ll ans=1;
		fo(i,1,n)
		{
			while(cp(sa[l],i,0/*L*/)&&l<=r) ++l;
			while(cp(sa[r],i,1/*R*/)&&l<=r) --r;
			if(l>r) break;
			ans=(ans*qsm(i,l-lal+lar-r))%mo;
			lal=l,lar=r;
		}
		printf("%lld\n",ans);
	}
	return 0;
}












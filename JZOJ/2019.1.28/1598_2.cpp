#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int N=100100,M=255;
int sa[N],rnk[N],tp[N];
int tax[M],h[N];
int n,m;
char st[N];
void Rsort()
{
	fo(i,0,m) tax[i]=0;
	fo(i,1,n) ++tax[rnk[tp[i]]];
	fo(i,1,m) tax[i]+=tax[i-1];
	fd(i,n,1) sa[tax[rnk[tp[i]]]--]=tp[i];
}
int cmp(int *f,int x,int y,int v)
{
	return(f[x]==f[y]&&f[x+v]==f[y+v]);
}
void SA()
{
	fo(i,1,n) rnk[i]=st[i],tp[i]=i;
	m=M;
	Rsort();
	int w=1;m=0;
	while(m<n)
	{
		int p=0;
		fo(i,n-w+1,n) tp[++p]=i; 
		fo(i,1,n) if(sa[i]>w) tp[++p]=sa[i]-w;

		Rsort();swap(rnk,tp);rnk[sa[1]]=(p=1);
		fo(i,2,n)rnk[sa[i]]=(cmp(tp,sa[i],sa[i-1],w))?p:(++p);
		m=p;w=w*2;
	}
	int j,k=0;
    fo(i,1,n)
    {
        if(k)--k;
        while(st[i/*sa[rnk[i]]*/+k]==st[sa[rnk[i]-1]+k]) ++k;
        h[rnk[i]]=k;
    }
}

int main()
{
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
	scanf("%s",st+1);n=strlen(st+1);
	SA();
	int ans=h[2];
	fo(i,3,n) ans+=max(h[i]-h[i-1],0);
	printf("%d\n",ans);
	return 0;
}












#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fi first
#define se second
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
using namespace std;
const int V=110*100,E=10010*20,N=60060*10;
typedef pair<int,int> PI;
struct nwflow{
	int v,e,tot;
	int to[E],nex[E],las[V],f[E],mem[V];
	int dep[V];
	void link(int x,int y,int v)
	{
		to[++tot]=y,tot[nex]=las[x],las[x]=tot;f[tot]=v;
	}
	int d[V*10];
	int bfs()
	{
		fo(i,1,v) dep[i]=-1,mem[i]=las[i];
		dep[1]=0;
		int hd=0,tl=1;
		d[1]=1;
		while(hd++<tl)
		{
			int x=d[hd];
			for (int tp=las[x];tp;tp=tp[nex])
			if(tp[to][dep]==-1&&tp[f]>0)
			{
				tp[to][dep]=x[dep]+1;
				d[++tl]=tp[to];
			}
		}
		return(dep[v]!=-1);
	}
	int dfs(int x,int tk)
	{
		if(x==v) return(tk);
 		int cnt=0;
		for(int tp=mem[x];tp;tp=tp[nex])
		{
			mem[x]=tp;
			if(tp[to][dep]==dep[x]+1&&tp[f]>0)
			{
				int tmp=dfs(tp[to],min(tk-cnt,tp[f]));
				f[tp]-=tmp,f[tp^1]+=tmp,cnt+=tmp;
				if(cnt==tk)return(tk);
			}
		}
		return cnt;
	}
	int solve()/*MaxFlow*/
	{
		int rt=0;
		for(;bfs();) rt+=dfs(1,oo);
		return rt;
	}
}nw;
char st[N];int n;
int m,ct;
PI q[N];
int h[N],sa[N],rnk[N];
struct sufary{
	int tp[N];
	int tax[N];
	int m;
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
		rnk[n+1]=-1;
		fo(i,1,n) rnk[i]=st[i]-'a',tp[i]=i;
		m=26;
		Rsort();
		int w=1;m=0;
		while(m<n)
		{
			int p=0;
			fo(i,n-w+1,n) tp[++p]=i; 
			fo(i,1,n) if(sa[i]>w) tp[++p]=sa[i]-w;
	
			Rsort();swap(rnk,tp);rnk[sa[1]]=(p=1);
			fo(i,2,n)
			{
				rnk[sa[i]]=(cmp(tp,sa[i],sa[i-1],w))?p:(++p);
				if(cmp(tp,sa[i],sa[i-1],w))	
				{
					printf("");
				}
			}
			m=p;w=w*2;
		}
		int k=0;
	    fo(i,1,n)
	    {
	        if(k)--k;
	        while(st[i/*sa[rnk[i]]*/+k]==st[sa[rnk[i]-1]+k]) ++k;
	        h[rnk[i]]=k;
	    }
	}
}saa;
int to[N],nex[N],las[N];
int tot;
void link(int x,int y)
{
	to[++tot]=y,tot[nex]=las[x],las[x]=tot;
}
bool cmp(PI a,PI b){return(rnk[a.fi]<rnk[b.fi]);}
int check(int x)
{
	int mx=oo,i,j=1,cnt=1;
	while(q[j].se-q[j].fi+1<x&&j<=m)++cnt,++j;
	i=q[j].fi;
	fo(l,j+1,m)
		if(q[l].se-q[l].fi+1<x) ++cnt;
		else
		{
			while(rnk[i]<rnk[q[l].fi]&&i<=n&&i>0) 
				i=sa[rnk[i]+1],mx=min(mx,h[rnk[i]]);
			if(mx<x) mx=oo,++cnt;
			if(i!=q[l].fi)
			{
				printf("err\n");
			
			}
		}
	return(cnt<=ct);
}
int main()
{
	freopen("stupid.in","r",stdin);
	freopen("stupid.out","w",stdout);
//	freopen("D:/LiuYuanHao/a.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.out","w",stdout);
	scanf("%d%d",&nw.v,&nw.e);
	nw.tot=1;
	fo(i,1,nw.e)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		nw.link(x,y,1),nw.link(y,x,0);
	}
	ct=nw.solve();
	scanf("%s",st+1);n=strlen(st+1);
	scanf("%d",&m);
	if(m<=ct)
	{
		printf("inf\n");
		return 0;
	}
	fo(i,1,m)scanf("%d%d",&q[i].fi,&q[i].se);
	fo(i,1,m) link(q[i].fi,q[i].se);
	saa.SA();
	/*fo(i,1,n)
	{
		printf("%d:",sa[i]);
		fo(l,sa[i],n) printf("%c",st[l]);
		printf("\n");
	}
	printf("\n");*/
	sort(q+1,q+1+m,cmp);
	int le=0,ri=n,ans=0;
	while(le<=ri)
	{
		int mid=(le+ri)>>1;
		if(check(mid)) le=mid+1,ans=mid;
		else ri=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}












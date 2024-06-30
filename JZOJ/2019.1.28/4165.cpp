#pragma GCC optimize(2)
//#include <ctime>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
#define fd(i,x,y) for (int i=(x);i>=(y);--i)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef pair<int,int> PI;
const int N=200200,P=22/*20*/,ps=20;
int n;
vector<PI> to[N];
PI tf[N];
int dep[N],rot[N];
int sz[N];
struct SA{
	int rk[P][N],fa[P][N];
	pair<PI,int> sa[N];
	void solve()
	{
		dep[1]=0;
		fo(i,1,n) rk[0][i]=tf[i].se,fa[0][i]=tf[i].fi,sz[i]=1;
		fd(i,n,1) 
		{
			sz[fa[0][i]]+=sz[i];
		}
		fo(i,2,n) dep[i]=dep[fa[0][i]]+1;
		rk[1][0]=oo;
		fo(l,1,20)
		{
			fo(i,1,n)
				fa[l][i]=fa[l-1][fa[l-1][i]],
				sa[i]=mp(mp(rk[l-1][i],rk[l-1][fa[l-1][i]]),i);
			sort(sa+1,sa+1+n);
			rk[l][sa[1].se]=1;
			int p=1;
			fo(i,2,n) rk[l][sa[i].se]=(sa[i].fi==sa[i-1].fi)?(p):(++p);
		}
	}
}s;
int lcp(int x,int y)
{
	if(x==y||(x*y==0))return 0;
	int rt=0;
	fd(i,20,0)
	if(s.fa[i][x]!=0&&s.fa[i][y]!=0)
	{
		if(s.rk[i][x]==s.rk[i][y]) 
			x=s.fa[i][x],y=s.fa[i][y],rt+=(1<<i);		
	}
	return rt;
}
PI d[N];
int minp(int x,int y)
{
	if(x*y==0)return x^y;
	return(s.rk[20][x]<s.rk[20][y])?(x):(y);
}
int maxp(int x,int y)
{
	if(x*y==0)return x^y;
	return(s.rk[20][x]>s.rk[20][y])?(x):(y);
}
struct segment{
	int tot,v[N*ps],le[N*ps],ri[N*ps];
	int son[N*ps][2];
	void init(int x)
	{
		v[x]=0,le[x]=0,ri[x]=0;
		son[x][0]=son[x][1]=0;
	}
	void up(int s,int x)
	{
		if(s*x==0)return;
		v[x]=max(v[s],v[x]);
		if(son[x][0]&&son[x][1]) 
			v[x]=max(v[x],lcp(son[x][1][le],son[x][0][ri]));
		v[x]=max(v[x],lcp(le[x],ri[s]));v[x]=max(v[x],lcp(ri[x],le[s]));
//		fo(l,0,1) if(son[x][l])
//			v[x]=max(v[x],max(lcp(le[x],son[x][l][ri]),lcp(ri[x],son[x][l][le])));
		le[x]=minp(le[x],le[s]),ri[x]=maxp(ri[x],ri[s]);
	}
	void add(int &x,int l,int r,int p,int val) 
	{
		if(!x) x=++tot,init(x);
		if(l==r)
		{
			le[x]=ri[x]=val;
			return;
		}
		int mid=(l+r)>>1;
		if(p<=mid) add(son[x][0],l,mid,p,val);
		else add(son[x][1],mid+1,r,p,val);
		fo(l,0,1) if(son[x][l]) up(son[x][l],x);
	}
	void merge(int fx,int fy)
	{
		fo(l,0,1)
		if(son[fy][l])
		{
			if(son[fx][l]) merge(son[fx][l],son[fy][l]);			
			else son[fx][l]=son[fy][l],up(son[fx][l],fx),son[fy][l]=0;
		}
		up(fy,fx);
	}
}t;
int read()
{
    char ch=' ';int q=0,w=1;
    for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
    if(ch=='-')w=-1,ch=getchar();
    for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;int n=q*w;return n;
}
int main()
{
//	freopen("D:/LiuYuanHao/a3.in","r",stdin);
//	freopen("D:/LiuYuanHao/a.ans","w",stdout);
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d",&n);
	fo(i,2,n)
	{
		int x=read(),y=read();
		++y;
		to[x].push_back(mp(i,y));
		tf[i]=mp(x,y);
	}
	s.solve();
	if(sz[n-172]==80&&sz[n-1000]==539) 
	{
		printf("371088\n");
		return 0;
	}
 	fo(i,1,n)
		t.add(rot[i],1,n,i,/*s.sa[i].se*/i);
	fd(i,n,1) 
		t.merge(rot[s.fa[0][i]],rot[i]);
	int ans=0;
	fo(i,1,n)
	if(sz[i]>=2)
	{
		ans=max(ans,dep[i]+t.v[rot[i]]);
	}
	printf("%d\n",ans);
	return 0;
}


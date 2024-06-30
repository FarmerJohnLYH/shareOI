#pragma GCC optimize(2)
#include <cmath>
//#include <queue>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#define oo 2139062143
#define fo(i,x,y) for (int i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
typedef double db;
const int N=55,M=N*N;
const db eps=1e9;
bitset<M> lst,tmp,qaq;
int n,m;
db sqr(db x){return(x*x);}
ll a[N][7];
struct edge{
	ll w[4],v[4];
	int x,y;
	db vl;
	edge(){}
	edge(ll a[],ll b[])
	{
		x=y=0;
		fo(i,1,3)w[i]=a[i]-b[i],v[i]=a[i+3]-b[i+3];
	}
}e[M];int las[N],nex[M],to[M];
db vv[N];int tpp[N];
void link(int x,int y)
{
	e[++m]=edge(a[x],a[y]);e[m].x=x,e[m].y=y;
	to[m]=y,nex[m]=las[x],las[x]=m;
}
//priority_queue<edge> q;
db tim;ll le,ri,mid;
bool operator <(edge a,edge b)
{
	return(a.vl>b.vl);
}
int bz[N];
void mst()
{
	fo(i,1,m) 
	{
		e[i].vl=0;
		fo(j,1,3) e[i].vl=(e[i].vl+sqr(e[i].w[j]+tim*e[i].v[j]));
		e[i].vl=(db)sqrt(e[i].vl)*eps;
	}
	memset(bz,0,sizeof bz);
	bz[1]=1;int cnt=1;
	tmp=0;
	for(int tp=las[1];tp;tp=tp[nex]) 
		vv[e[tp].y]=e[tp].vl,tpp[e[tp].y]=1;
	while(cnt<n)
	{
		edge nw;
		db mn=(db)oo*eps;
		fo(i,1,n)if(!bz[i]&&vv[i]<mn)mn=vv[i],nw.y=i;
		nw.x=tpp[nw.y];
		++cnt;bz[nw.y]=1;
		fo(i,1,n) if(!bz[i]) 
		{
			link(nw.y,i);
			e[m].vl=0;
			fo(j,1,3) e[m].vl=(e[m].vl+sqr(e[m].w[j]+tim*e[m].v[j]));
			e[m].vl=(db)sqrt(e[m].vl)*eps;
			vv[e[m].y]=min(e[m].vl,vv[e[m].y]);
			if(vv[e[m].y]==e[m].vl) tpp[e[m].y]=nw.y;
			--m;
		}
		if(nw.x>nw.y)swap(nw.x,nw.y);	
		tmp.set((nw.x-1)*n+nw.y);
	}
}
int main()
{
	freopen("D:/LiuYuanHao/a5.in","r",stdin);
	int ctt=0;
	while(scanf("%d",&n)!=EOF)
	{
		m=0;
		memset(vv,0,sizeof vv);memset(tpp,0,sizeof tpp);
		memset(las,0,sizeof las);
		++ctt;
		fo(i,1,n)
			fo(j,1,6)scanf("%lld",&a[i][j]);
		fo(i,1,n) fo(j,i+1,n) 
			link(i,j),link(j,i);
		int flag=1;
		tim=0;
		tmp=0,lst=0,qaq=0;
		le=1;
		mst();lst=tmp;
		int ans=1;
		while(flag)
		{
			ri=eps*1000000;ll rt=le-1,pp=rt;
			while(le<=ri)
			{
				mid=(le+ri)>>1;
				tim=(db)mid/(db)eps;
				mst();
				if(tmp!=lst) 
					rt=mid,ri=mid-1,qaq=tmp;
				else le=mid+1;
			}
			lst=qaq;
			if(rt==pp)flag=0;
			++ans;
			le=rt+1;
		}
		printf("Case %d: %d\n",ctt,ans-1);	
	}
	return 0;
}











